/*
 *
 */

#include "hbxlib.ch"

PROCEDURE Main()

   LOCAL dpy
   LOCAL win
   LOCAL screen
   LOCAL screenId
   LOCAL quit := .F.
   LOCAL event
   LOCAL text := "Hello, World!"

   IF( ( dpy := XOpenDisplay( NIL ) ) == NIL )
      RETURN
   ENDIF

   screen   := XDefaultScreenOfDisplay( dpy )
   screenId := XDefaultScreen( dpy )

   win := XCreateSimpleWindow( dpy, XRootWindowOfScreen( screen ), 0, 0, 720, 450, 1, XBlackPixel( dpy, screenId ), XWhitePixel( dpy, screenId ) )

   XSelectInput( dpy, win, hb_bitOr( KeyPressMask, ExposureMask ) )

   XClearWindow( dpy, win )
   XMapRaised( dpy, win )

   WHILE( ! quit )

      WHILE( XPending( dpy ) != 0 )

         XNextEvent( dpy, @event )

         IF( event == Expose )
            XFillRectangle( dpy, win, XDefaultGC( dpy, screenId ), 20, 20, 10, 10 )
            XDrawString( dpy, win, XDefaultGC( dpy, screenId ), 50, 50, text, Len( text ) )
         ENDIF

         IF( event == KeyPress )
            quit := .T.
            EXIT
         ENDIF

      ENDDO

   ENDDO

   XDestroyWindow( dpy, win )
   XCloseDisplay( dpy )

   RETURN
