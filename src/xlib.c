/*
 * Xlib: xlib.c
 *
 * Copyright Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "hbxlib.h"

// XActivateScreenSaver
// XAddConnectionWatch
// XAddExtension
// XAddHost
// XAddHosts
// XAddToExtensionList
// XAddToSaveSet
// XAllocColor
// XAllocColorCells
// XAllocColorPlanes
// XAllocNamedColor
// XAllowEvents
// XAllPlanes
// XAutoRepeatOff
// XAutoRepeatOn
// XBaseFontNameListOfFontSet
// XBell
// XBitmapBitOrder
// XBitmapPad
// XBitmapUnit

// extern unsigned long XBlackPixel( Display *display, int screen_number );
HB_FUNC( XBLACKPIXEL )
{
   Display *display = hb_parptr( 1 );

   if( display && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      hb_retnl( ( unsigned long ) XBlackPixel( display, hb_parni( 2 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XBlackPixelOfScreen
// XCellsOfScreen
// XChangeActivePointerGrab
// XChangeGC
// XChangeKeyboardControl
// XChangeKeyboardMapping
// XChangePointerControl
// XChangeProperty
// XChangeSaveSet
// XChangeWindowAttributes
// XCheckIfEvent
// XCheckMaskEvent
// XCheckTypedEvent
// XCheckTypedWindowEvent
// XCheckWindowEvent
// XCirculateSubwindows
// XCirculateSubwindowsDown
// XCirculateSubwindowsUp
// XClearArea

// extern int XClearWindow( Display *display, Window w );
HB_FUNC( XCLEARWINDOW )
{
   Display *display = hb_parptr( 1 );

   if( display && hb_param( 2, HB_IT_LONG ) != NULL )
   {
      hb_retni( XClearWindow( display, ( unsigned long ) hb_parnl( 2 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// extern int XCloseDisplay( Display *display );
HB_FUNC( XCLOSEDISPLAY )
{
   Display *display = hb_parptr( 1 );

   if( display )
   {
      XCloseDisplay( display );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XCloseIM
// XCloseOM
// XConfigureWindow
// XConnectionNumber
// XContextDependentDrawing
// XContextualDrawing
// XConvertSelection
// XCopyArea
// XCopyColormapAndFree
// XCopyGC
// XCopyPlane
// XCreateBitmapFromData

// extern Colormap XCreateColormap( Display *display, Window w, Visual *visual, int alloc );
HB_FUNC( XCREATECOLORMAP )
{
   Display *display = hb_parptr( 1 );
   Visual *visual = hb_parptr( 3 );

   if( display && hb_param( 2, HB_IT_LONG ) != NULL && visual && hb_param( 4, HB_IT_INTEGER ) != NULL )
   {
      hb_retnl( ( unsigned long ) XCreateColormap( display, ( unsigned long ) hb_parnl( 2 ), visual, hb_parni( 4 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XCreateFontCursor
// XCreateGC
// XCreateGlyphCursor
// XCreateImage
// XCreateOC
// XCreatePixmap
// XCreatePixmapCursor
// XCreatePixmapFromBitmapData


// extern Window XCreateSimpleWindow( Display *display, Window parent, int x, int y, unsigned int width, unsigned int height, unsigned int border_width, unsigned long border, unsigned long background );
HB_FUNC( XCREATESIMPLEWINDOW )
{
   Display *display = hb_parptr( 1 );

   if( display &&
      hb_param( 2, HB_IT_LONG ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      hb_param( 5, HB_IT_INTEGER ) != NULL &&
      hb_param( 6, HB_IT_INTEGER ) != NULL &&
      hb_param( 7, HB_IT_INTEGER ) != NULL &&
      hb_param( 8, HB_IT_LONG    ) != NULL &&
      hb_param( 9, HB_IT_LONG    ) != NULL )
   {
      hb_retnl( ( unsigned long ) XCreateSimpleWindow( display, ( unsigned long ) hb_parnl( 2 ), hb_parni( 3 ), hb_parni( 4 ),
         ( unsigned int ) hb_parni( 5 ), ( unsigned int ) hb_parni( 6 ), ( unsigned int ) hb_parni( 7 ),
         ( unsigned long ) hb_parnl( 8 ), ( unsigned long ) hb_parnl( 9 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

/* extern Window XCreateWindow( Display *display, Window parent, int x, int y, unsigned int width, unsigned int height, unsigned int border_width,
                                int depth, unsigned int class, Visual *visual, unsigned long valuemask, XSetWindowAttributes* attributes ); */
HB_FUNC( XCREATEWINDOW )
{
   Display *display = hb_parptr( 1 );
   Visual *visual = hb_parptr( 10 );
   PHB_ITEM pItem;

   if( display &&
      hb_param( 2, HB_IT_LONG ) != NULL &&
      hb_param( 3, HB_IT_INTEGER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      hb_param( 5, HB_IT_INTEGER ) != NULL &&
      hb_param( 6, HB_IT_INTEGER ) != NULL &&
      hb_param( 7, HB_IT_INTEGER ) != NULL &&
      hb_param( 8, HB_IT_INTEGER ) != NULL &&
      hb_param( 9, HB_IT_INTEGER ) != NULL &&
      hb_param( 10, HB_IT_POINTER ) != NULL &&
      hb_param( 11, HB_IT_NUMERIC ) != NULL &&
      ( pItem = hb_param( 12, HB_IT_ARRAY ) ) != NULL )
   {
      XSetWindowAttributes swa;
      memset( &swa, 0, sizeof( swa ) );

      swa.background_pixmap     = hb_arrayGetNL( pItem, 1 );   // Pixmap
      swa.background_pixel      = hb_arrayGetNL( pItem, 2 );   // unsigned long
      swa.border_pixmap         = hb_arrayGetNL( pItem, 3 );   // Pixmap
      swa.border_pixel          = hb_arrayGetNL( pItem, 4 );   // unsigned long
      swa.bit_gravity           = hb_arrayGetNI( pItem, 5 );   // int
      swa.win_gravity           = hb_arrayGetNI( pItem, 6 );   // int
      swa.backing_store         = hb_arrayGetNI( pItem, 7 );   // int
      swa.backing_planes        = hb_arrayGetNL( pItem, 8 );   // unsigned long
      swa.backing_pixel         = hb_arrayGetNL( pItem, 9 );   // unsigned long
      swa.save_under            = hb_arrayGetL ( pItem, 10 );  // Bool
      swa.event_mask            = hb_arrayGetNL( pItem, 11 );  // long
      swa.do_not_propagate_mask = hb_arrayGetNL( pItem, 12 );  // long
      swa.override_redirect     = hb_arrayGetL ( pItem, 13 );  // Bool
      swa.colormap              = hb_arrayGetNL( pItem, 14 );  // Colormap
      swa.cursor                = hb_arrayGetNI( pItem, 15 );  // Cursor

      hb_retnl( ( unsigned long ) XCreateWindow( display, ( unsigned long ) hb_parnl( 2 ), hb_parni( 3 ), hb_parni( 4 ), ( unsigned int ) hb_parni( 5 ),
         ( unsigned int ) hb_parni( 6 ), ( unsigned int ) hb_parni( 7 ), hb_parni( 8 ), ( unsigned int ) hb_parni( 9 ), visual,
         ( unsigned long ) hb_parnl( 11 ), &swa ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XDefaultColormap
// XDefaultColormapOfScreen

// extern int XDefaultDepth( Display *display, int screen_number );
HB_FUNC( XDEFAULTDEPTH )
{
   Display *display = hb_parptr( 1 );

   if( display && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      hb_retni( XDefaultDepth( display, hb_parni( 2 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}


// XDefaultDepthOfScreen

// extern GC XDefaultGC( Display *display, int screen_number );
HB_FUNC( XDEFAULTGC )
{
   Display *display = hb_parptr( 1 );

   if( display && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      hb_retptr( XDefaultGC( display, hb_parni( 2 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XDefaultGCOfScreen


// extern Window XDefaultRootWindow( Display *display );
HB_FUNC( XDEFAULTROOTWINDOW )
{
   Display *display = hb_parptr( 1 );

   if( display )
   {
      hb_retnl( ( unsigned long ) XDefaultRootWindow( display ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// extern int XDefaultScreen( Display *display );
HB_FUNC( XDEFAULTSCREEN )
{
   Display *display = hb_parptr( 1 );

   if( display )
   {
      hb_retni( XDefaultScreen( display ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// extern Screen *XDefaultScreenOfDisplay( Display *display );
HB_FUNC( XDEFAULTSCREENOFDISPLAY )
{
   Display *display = hb_parptr( 1 );

   if( display )
   {
      hb_retptr( XDefaultScreenOfDisplay( display ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// extern Visual *XDefaultVisual( Display *display, int screen_number );
HB_FUNC( XDEFAULTVISUAL )
{
   Display *display = hb_parptr( 1 );

   if( display && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      hb_retptr( XDefaultVisual( display, hb_parni( 2 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XDefaultVisualOfScreen
// XDefineCursor
// XDeleteModifiermapEntry
// XDeleteProperty
// XDestroyIC
// XDestroyOC
// XDestroySubwindows


// extern int XDestroyWindow( Display *display, Window window );
HB_FUNC( XDESTROYWINDOW )
{
   Display *display = hb_parptr( 1 );

   if( display && hb_param( 2, HB_IT_LONG ) != NULL )
   {
      hb_retni( XDestroyWindow( display, ( unsigned long ) hb_parnl( 2 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XDirectionalDependentDrawing
// XDisableAccessControl
// XDisplayCells
// XDisplayHeight
// XDisplayHeightMM
// XDisplayKeycodes
// XDisplayMotionBufferSize
// XDisplayName
// XDisplayOfIM
// XDisplayOfOM
// XDisplayOfScreen
// XDisplayPlanes
// XDisplayString
// XDisplayWidth
// XDisplayWidthMM
// XDoesBackingStore
// XDoesSaveUnders
// XDrawArc
// XDrawArcs
// XDrawImageString
// XDrawImageString16
// XDrawLine
// XDrawLines
// XDrawPoint
// XDrawPoints
// XDrawRectangle
// XDrawRectangles
// XDrawSegments

//extern int XDrawString( Display *display, Drawable d, GC gc, int x, int y, _Xconst char* string, int length );
HB_FUNC( XDRAWSTRING )
{
   Display *display = hb_parptr( 1 );

   if( display &&
      hb_param( 2, HB_IT_LONG ) != NULL &&
      hb_param( 3, HB_IT_POINTER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      hb_param( 5, HB_IT_INTEGER ) != NULL &&
      hb_param( 6, HB_IT_STRING )  != NULL &&
      hb_param( 7, HB_IT_INTEGER ) != NULL )
   {
      hb_retni( XDrawString( display, ( unsigned long ) hb_parnl( 2 ), hb_parptr( 3 ), hb_parni( 4 ), hb_parni( 5 ), hb_parc( 6 ), hb_parni( 7 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XDrawString16
// XDrawText
// XDrawText16
// XEHeadOfExtensionList
// XEnableAccessControl
// XErrorHandler XSetErrorHandler
// XEventMaskOfScreen
// XEventsQueued
// XExtendedMaxRequestSize
// XFetchBuffer
// XFetchBytes
// XFetchName
// XFillArc
// XFillArcs
// XFillPolygon

// extern int XFillRectangle( Display *display, Drawable drawable, GC gc, int x, int y, unsigned int width, unsigned int height );
HB_FUNC( XFILLRECTANGLE )
{
   Display *display = hb_parptr( 1 );

   if( display &&
      hb_param( 2, HB_IT_LONG ) != NULL &&
      hb_param( 3, HB_IT_POINTER ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL &&
      hb_param( 5, HB_IT_INTEGER ) != NULL &&
      hb_param( 6, HB_IT_INTEGER ) != NULL &&
      hb_param( 7, HB_IT_INTEGER ) != NULL )
   {
      hb_retni( XFillRectangle( display, ( unsigned long ) hb_parnl( 2 ), hb_parptr( 3 ), hb_parni( 4 ), hb_parni( 5 ), ( unsigned int ) hb_parni( 6 ), ( unsigned int ) hb_parni( 7 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XFillRectangles

// extern Bool XFilterEvent( XEvent *event, Window window );
HB_FUNC( XFILTEREVENT )
{
   XEvent event;

   if( hb_param( 1, HB_IT_BYREF ) != NULL && hb_param( 2, HB_IT_LONG ) != NULL )
   {
      hb_retl( XFilterEvent( &event, ( unsigned long ) hb_parnl( 2 ) ) );
      hb_stornint( event.type, 1 );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XFindOnExtensionList

// extern int XFlush( Display *display );
HB_FUNC( XFLUSH )
{
   Display *display = hb_parptr( 1 );

   if( display )
   {
      hb_retni( XFlush( display ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XFlushGC
// XFontSet XCreateFontSet
// XFontSetExtents XExtentsOfFontSet
// XFontsOfFontSet
// XForceScreenSaver
// XFree

// extern int XFreeColormap( Display *display, Colormap colormap );
HB_FUNC( XFREECOLORMAP )
{
   Display *display = hb_parptr( 1 );

   if( display && hb_param( 2, HB_IT_LONG ) != NULL )
   {
      hb_retni( XFreeColormap( display, ( unsigned long ) hb_parnl( 2 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XFreeColors
// XFreeCursor
// XFreeEventData
// XFreeExtensionList
// XFreeFont
// XFreeFontInfo
// XFreeFontNames
// XFreeFontPath
// XFreeFontSet
// XFreeGC
// XFreeModifiermap
// XFreePixmap
// XFreeStringList
// XGContextFromGC
// XGeometry
// XGetAtomName
// XGetAtomNames
// XGetCommand
// XGetDefault
// XGetErrorDatabaseText
// XGetErrorText
// XGetEventData
// XGetFontPath
// XGetFontProperty
// XGetGCValues
// XGetGeometry
// XGetIconName
// XGetICValues
// XGetImage
// XGetIMValues
// XGetInputFocus
// XGetKeyboardControl
// XGetKeyboardMapping
// XGetModifierMapping
// XGetMotionEvents
// XGetOCValues
// XGetOMValues
// XGetPointerControl
// XGetPointerMapping
// XGetScreenSaver
// XGetSelectionOwner
// XGetSubImage
// XGetTransientForHint

// extern Status XGetWindowAttributes( Display *display, Window w, XWindowAttributes* window_attributes_return );
HB_FUNC( XGETWINDOWATTRIBUTES )
{
   Display *display = hb_parptr( 1 );

   if( display && hb_param( 2, HB_IT_LONG ) != NULL )
   {
      XWindowAttributes wa;

      hb_retni( XGetWindowAttributes( display, ( unsigned long ) hb_parnl( 2 ), &wa ) );

      hb_reta( 23 );
      hb_storvni(  wa.x,                     -1, 1 );
      hb_storvni(  wa.y,                     -1, 2 );
      hb_storvni(  wa.width,                 -1, 3 );
      hb_storvni(  wa.height,                -1, 4 );
      hb_storvni(  wa.border_width,          -1, 5 );
      hb_storvni(  wa.depth,                 -1, 6 );
      hb_storvptr( wa.visual,                -1, 7 );
      hb_storvnl(  wa.root,                  -1, 8 );
      hb_storvni(  wa.class,                 -1, 9 );
      hb_storvni(  wa.bit_gravity,           -1, 10 );
      hb_storvni(  wa.win_gravity,           -1, 11 );
      hb_storvni(  wa.backing_store,         -1, 12 );
      hb_storvnl(  wa.backing_planes,        -1, 13 );
      hb_storvnl(  wa.backing_pixel,         -1, 14 );
      hb_storvl(   wa.save_under,            -1, 15 );
      hb_storvnl(  wa.colormap,              -1, 16 );
      hb_storvl(   wa.map_installed,         -1, 17 );
      hb_storvni(  wa.map_state,             -1, 18 );
      hb_storvnl(  wa.all_event_masks,       -1, 19 );
      hb_storvnl(  wa.your_event_mask,       -1, 20 );
      hb_storvnl(  wa.do_not_propagate_mask, -1, 21 );
      hb_storvl(   wa.override_redirect,     -1, 22 );
      hb_storvptr( wa.screen,                -1, 23 );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XGetWindowProperty
// XGetWMColormapWindows
// XGetWMProtocols
// XGrabButton
// XGrabKey
// XGrabKeyboard
// XGrabPointer
// XGrabServer
// XHeightMMOfScreen
// XHeightOfScreen
// XIC XCreateIC
// XIconifyWindow
// XIfEvent
// XImageByteOrder
// XIMOfIC
// XInitExtension
// XInitImage
// XInitThreads
// XInsertModifiermapEntry
// XInstallColormap
// XInternalConnectionNumbers

// extern Atom XInternAtom( Display *display, _Xconst char* atom_name, Bool only_if_exists );
HB_FUNC( XINTERNATOM )
{
   Display *display = hb_parptr( 1 );

   if( display &&
      hb_param( 2, HB_IT_STRING ) != NULL  &&
      hb_param( 3, HB_IT_LOGICAL ) != NULL )
   {
      hb_retnl( ( unsigned long ) XInternAtom( display, hb_parc( 2 ), hb_parl( 3 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XInternAtoms
// XIOErrorHandler XSetIOErrorHandler
// XKeycodeToKeysym
// XKeysymToKeycode
// XKeysymToString
// XKillClient
// XLastKnownRequestProcessed
// XListDepths
// XListExtensions
// XListFonts
// XListFontsWithInfo
// XListHosts
// XListInstalledColormaps
// XListProperties
// XLoadFont
// XLoadQueryFont
// XLocaleOfFontSet
// XLocaleOfIM
// XLocaleOfOM
// XLockDisplay
// XLookupColor

//extern KeySym XLookupKeysym( XKeyEvent* key_event, int index );

// XLowerWindow

// extern int XMapRaised( Display *display, Window w );
HB_FUNC( XMAPRAISED )
{
   Display *display = hb_parptr( 1 );

   if( display && hb_param( 2, HB_IT_LONG ) != NULL )
   {
      hb_retni( XMapRaised( display, ( unsigned long ) hb_parnl( 2 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XMapSubwindows

// extern int XMapWindow( Display *display, Window w );
HB_FUNC( XMAPWINDOW )
{
   Display *display = hb_parptr( 1 );

   if( display && hb_param( 2, HB_IT_LONG ) != NULL )
   {
      hb_retni( XMapWindow( display, ( unsigned long ) hb_parnl( 2 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XMaskEvent
// XMaxCmapsOfScreen
// XMaxRequestSize
// XmbDrawImageString
// XmbDrawString
// XmbDrawText
// XmbLookupString
// XmbResetIC
// XmbTextEscapement
// XmbTextExtents
// XmbTextPerCharExtents
// XMinCmapsOfScreen
// XMoveResizeWindow
// XMoveWindow
// XNewModifiermap

// extern int XNextEvent( Display *display, XEvent *event_return );
HB_FUNC( XNEXTEVENT )
{
   Display *display = hb_parptr( 1 );
   XEvent event;

   if( display && hb_param( 2, HB_IT_BYREF ) != NULL )
   {
      hb_retni( XNextEvent( display, &event ) );
      hb_stornint( event.type, 2 );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XNextRequest
// XNoOp
// XOMOfOC

// extern Display *XOpenDisplay( _Xconst char* display_name );
HB_FUNC( XOPENDISPLAY )
{
   hb_retptr( XOpenDisplay( NULL ) );
}

// XOpenIM
// XOpenOM
// XParseColor
// XParseGeometry
// XPeekEvent
// XPeekIfEvent

// extern int XPending( Display *display );
HB_FUNC( XPENDING )
{
   Display *display = hb_parptr( 1 );

   if( display )
   {
      hb_parni( XPending( display ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XPixmapFormatValues XListPixmapFormats
// XPlanesOfScreen
// XProcessInternalConnection
// XProtocolRevision
// XProtocolVersion
// XPutBackEvent
// XPutImage
// XQLength
// XQueryBestCursor
// XQueryBestSize
// XQueryBestStipple
// XQueryBestTile
// XQueryColor
// XQueryColors
// XQueryExtension
// XQueryFont
// XQueryKeymap
// XQueryPointer
// XQueryTextExtents
// XQueryTextExtents16
// XQueryTree
// XRaiseWindow
// XReadBitmapFile
// XReadBitmapFileData
// XRebindKeysym
// XRecolorCursor
// XReconfigureWMWindow
// extern int XRefreshKeyboardMapping( XMappingEvent* event_map );
// XRegisterIMInstantiateCallback
// XRemoveConnectionWatch
// XRemoveFromSaveSet
// XRemoveHost
// XRemoveHosts
// XReparentWindow
// XResetScreenSaver
// XResizeWindow
// XResourceManagerString
// XRestackWindows
// XrmInitialize
// XRootWindow

// extern Window XRootWindowOfScreen( Screen* screen );
HB_FUNC( XROOTWINDOWOFSCREEN )
{
   //Screen* screen = hb_parptr( 1 );
   Screen * screen = hb_parptr( 1 );

   if( screen )
   {
      hb_retnl( ( unsigned long ) XRootWindowOfScreen( screen ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XRotateBuffers
// XRotateWindowProperties
// XScreenCount
// XScreenNumberOfScreen
// XScreenOfDisplay
// XScreenResourceString

// extern int XSelectInput( Display *display, Window w, long event_mask );
HB_FUNC( XSELECTINPUT )
{
   Display *display = hb_parptr( 1 );

   if( display &&
      hb_param( 2, HB_IT_LONG ) != NULL &&
      hb_param( 3, HB_IT_NUMERIC ) != NULL )
   {
      hb_retni( XSelectInput( display, ( unsigned long ) hb_parnl( 2 ), hb_parnl( 3 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XSendEvent
// XServerVendor
// XSetAccessControl
// XSetAfterFunction
// XSetArcMode
// XSetAuthorization
// XSetBackground
// XSetClipMask
// XSetClipOrigin
// XSetClipRectangles
// XSetCloseDownMode
// XSetCommand
// XSetDashes
// XSetFillRule
// XSetFillStyle
// XSetFont
// XSetFontPath
// XSetForeground
// XSetFunction
// XSetGraphicsExposures
// XSetICFocus
// XSetIconName
// XSetICValues
// XSetIMValues
// XSetInputFocus
// XSetLineAttributes
// XSetLocaleModifiers
// XSetModifierMapping
// XSetOCValues
// XSetOMValues
// XSetPlaneMask
// XSetPointerMapping
// XSetScreenSaver
// XSetSelectionOwner
// XSetState
// XSetStipple
// XSetSubwindowMode
// XSetTile
// XSetTransientForHint
// XSetTSOrigin
// XSetWindowBackground
// XSetWindowBackgroundPixmap
// XSetWindowBorder
// XSetWindowBorderPixmap
// XSetWindowBorderWidth
// XSetWindowColormap
// XSetWMColormapWindows

// extern Status XSetWMProtocols( Display *display, Window w, Atom* protocols, int count );
HB_FUNC( XSETWMPROTOCOLS )
{
   Display *display = hb_parptr( 1 );

   if( display &&
      hb_param( 2, HB_IT_LONG ) != NULL &&
      hb_param( 3, HB_IT_LONG ) != NULL &&
      hb_param( 4, HB_IT_INTEGER ) != NULL )
   {
      Atom protocols;
      hb_retni( XSetWMProtocols( display, ( unsigned long ) hb_parnl( 2 ), &protocols, hb_parni( 4 ) ) );
      hb_stornl( protocols, 3 );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XStoreBuffer
// XStoreBytes
// XStoreColor
// XStoreColors

// extern int XStoreName( Display *display, Window w, _Xconst char* window_name );
HB_FUNC( XSTORENAME )
{
   Display *display = hb_parptr( 1 );

   if( display &&
      hb_param( 2, HB_IT_LONG ) != NULL &&
      hb_param( 3, HB_IT_STRING ) != NULL )
   {
      hb_retni( XStoreName( display, ( unsigned long ) hb_parnl( 2 ), hb_parc( 3 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XStoreNamedColor
// XStringToKeysym
// XSupportsLocale void);
// XSync
// XSynchronize
// XTextExtents
// XTextExtents16
// XTextWidth
// XTextWidth16
// XTranslateCoordinates
// XUndefineCursor
// XUngrabButton
// XUngrabKey
// XUngrabKeyboard
// XUngrabPointer
// XUngrabServer
// XUninstallColormap
// XUnloadFont
// XUnlockDisplay
// XUnmapSubwindows

// extern int XUnmapWindow( Display *display, Window w );
HB_FUNC( XUNMAPWINDOW )
{
   Display *display = hb_parptr( 1 );

   if( display && hb_param( 2, HB_IT_LONG ) != NULL )
   {
      hb_retni( XUnmapWindow( display, ( unsigned long ) hb_parnl( 2 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XUnregisterIMInstantiateCallback
// XUnsetICFocus
// Xutf8DrawImageString
// Xutf8DrawString
// Xutf8DrawText

//extern int Xutf8LookupString( XIC ic, XKeyPressedEvent* event, char* buffer_return, int bytes_buffer, KeySym* keysym_return, Status* status_return );

// Xutf8ResetIC
// Xutf8TextEscapement
// Xutf8TextExtents
// Xutf8TextPerCharExtents
// XVaNestedList XVaCreateNestedList
// XVendorRelease
// XVisualIDFromVisual
// XWarpPointer
// XwcDrawImageString
// XwcDrawString
// XwcDrawText
// XwcLookupString
// XwcResetIC
// XwcTextEscapement
// XwcTextExtents
// XwcTextPerCharExtents

// extern unsigned long XWhitePixel( Display *display, int screen_number );
HB_FUNC( XWHITEPIXEL )
{
   Display *display = hb_parptr( 1 );

   if( display && hb_param( 2, HB_IT_INTEGER ) != NULL )
   {
      hb_retnl( ( unsigned long ) XWhitePixel( display, hb_parni( 2 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// XWhitePixelOfScreen
// XWidthMMOfScreen
// XWidthOfScreen
// XWindowEvent
// XWithdrawWindow
// XWriteBitmapFile
// _Xdebug
// _Xmblen
// _Xmbtowc
// _Xwctomb
