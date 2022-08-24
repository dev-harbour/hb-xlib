/*
 *
 */

#include "hbxlib.ch"

PROCEDURE Main()

   LOCAL dpy
   LOCAL root
   LOCAL screen
   LOCAL visual
   LOCAL colormap
   LOCAL swa[ 15 ]
   LOCAL win
   LOCAL width := 720, height := 450
   LOCAL sfc
   LOCAL cr
   LOCAL quit := .F.
   LOCAL event
   LOCAL gwa
   LOCAL te
   LOCAL text := "100 reasons why I love Harbour"
   LOCAL x, y

   IF( ( dpy := XOpenDisplay( NIL ) ) == NIL )
      RETURN
   ENDIF

   root     := XDefaultRootWindow( dpy )
   screen   := XDefaultScreen( dpy )
   visual   := XDefaultVisual( dpy, screen )
   colormap := XCreateColormap( dpy, root, visual, AllocNone )

   swa[ 11 ] := hb_bitOr( KeyPressMask, ExposureMask )
   swa[ 14 ] := colormap

   win := XCreateWindow( dpy, root, 0, 0, width, height, 0, XDefaultDepth( dpy, screen ), InputOutput, visual, hb_bitOr( CWEventMask, CWColormap ), @swa )

   XStoreName( dpy, win, "Xlib .AND. Cairo" )
   XMapWindow( dpy, win )

   sfc := cairo_xlib_surface_create( dpy, win, visual, width, height )
   cr  := cairo_create( sfc )

   WHILE( ! quit )

      WHILE( XPending( dpy ) != 0 )

         XNextEvent( dpy, @event )

         IF( event == Expose )
            gwa := XGetWindowAttributes( dpy, win )
            width  := gwa[ 3 ]
            height := gwa[ 4 ]

            cairo_xlib_surface_set_size( sfc, width, height )

            cairo_set_source_rgb( cr, 1.0, 1.0, 0.0 )
            cairo_set_operator( cr, CAIRO_OPERATOR_SOURCE )
            cairo_paint( cr )

            cairo_set_source_rgb( cr, 0.0, 0.0, 0.0 )
            cairo_select_font_face( cr, "FreeMono", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD )
            cairo_set_font_size( cr, 32 )

            te := cairo_text_extents( cr, text )

            x := ( width  - te[ 3 ] ) / 2
            y := ( height + te[ 4 ] ) / 2

            cairo_move_to( cr, x, y )
            cairo_show_text( cr, text )

         ENDIF

         IF( event == KeyPress )
            quit := .T.
            EXIT
         ENDIF

      ENDDO

   ENDDO

   cairo_surface_destroy( sfc )
   cairo_destroy( cr )

   XUnmapWindow( dpy, win )
   XFreeColormap( dpy, colormap )
   XDestroyWindow( dpy, win )
   XCloseDisplay( dpy )

   RETURN
