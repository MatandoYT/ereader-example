#include <erapi.h>
#include <gba_types.h>

extern u32 __end__;
const u16 palette[] = {0x0000, 0xFFFF};

int main()
{
  
  	// Initializes the Dotcode Application
  	ERAPI_FadeIn(1);
  	ERAPI_InitMemory((ERAPI_RAM_END - (u32)__end__) >> 10);

	// Set up the display
	ERAPI_SetBackgroundMode(0);
  	ERAPI_SetBackgroundPalette(&palette[0], 0x00, 0x02);

  	// Create a render region to display information
  	ERAPI_HANDLE_REGION region = ERAPI_CreateRegion(0, 0, 0x01, 0x01, 0x1C, 0x0D);
  	ERAPI_SetTextColor(region, 0x01, 0x00);

  	// Everything else goes here
  	ERAPI_DrawText(region, 0x10, 0x38, "Hello World!" );
    ERAPI_DrawText(region, 0x10, 0x40, "Press B to return to E-Reader Menu." );

    while(1)
    {
		
		// Detect button press by caling ERAPI_GetKeyStateSticky
    	u32 pressed = ERAPI_GetKeyStateSticky();
    	ERAPI_RenderFrame(1);
    	
    	// If the B button was pressed then we return
    	// to the E-Reader Main Menu
    	if (pressed & ERAPI_KEY_B)
    	{
    		break;
    	}
    }
 
  // exit
  return ERAPI_EXIT_TO_MENU;
}
