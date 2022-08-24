/*
 * Xlib: xlib.c
 *
 * Copyright Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbxlib.h"

// XSetWMName( wnd->dpy, wnd->window, &text );
HB_FUNC( XSETWMNAME )
{
   Display *display = hb_parptr( 1 );

   if( display &&
      hb_param( 2, HB_IT_LONG ) != NULL &&
      hb_param( 3, HB_IT_STRING ) != NULL )
   {
      const char * title = hb_parc( 3 );
      XTextProperty textprop;

      Atom s_atomUTF8String = XInternAtom( display, "UTF8_STRING", False );

      textprop.value = (unsigned char *) title;
      textprop.encoding = s_atomUTF8String;
      textprop.format = 8;
      textprop.nitems = strlen(title);

      XSetWMName( display, ( unsigned long ) hb_parnl( 2 ), &textprop );

   }
   else
   {
      HB_ERR_ARGS();
   }
}
