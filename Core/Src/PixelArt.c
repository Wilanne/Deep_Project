/**
 * @file PixelArt.c
 *
 * @brief This file contains the definition of all the PixelArt function
 *
 * @date 11 mai 2023
 * @author leoau
 */

#include "PixelArt.h"
#include "Pixils.h"

uint8_t delay = 115;

/**
 * @brief Initialize the screen for PixelArt.
 */
void PixelArt_InitScreen() {
	ILI9341_Init();
	ILI9341_FillScreen(DGY);
	ILI9341_SetRotation(SCREEN_VERTICAL_1);
}

/**
 * @brief Draw a grid on the screen.
 * @param m_gridColor The color of the grid lines.
 * @param m_fillColor The color to fill each cell of the grid.
 * @param m_cellSize The size of each cell in the grid.
 * @param m_scalFactor The scale factor to adjust the cell size.
 */
void PixelArt_DrawGrid(uint16_t m_gridColor, uint16_t m_fillColor, uint8_t m_cellSize, float m_scalFactor) {
	ILI9341_SetRotation(SCREEN_VERTICAL_1);

	uint16_t gridColor = m_gridColor; /* Specify the desired color for the grid */
	uint16_t fillColor = m_fillColor;

	// Define the size of each cell in the grid
	uint8_t cellSize = m_cellSize;

	if (m_scalFactor != 0)
		cellSize = (uint8_t)cellSize * m_scalFactor;

	// Define the position of the grid on the display
	uint16_t startX = (ILI9341_SCREEN_HEIGHT - 8 * cellSize) / 2;
	uint16_t startY = (ILI9341_SCREEN_WIDTH - 8 * cellSize) / 2;

	/* Draw grid only
	for (uint16_t i = 0; i <= 8; i++) {
		// Draw vertical lines
		uint16_t x = startX + i * cellSize;
		ILI9341_DrawVLine(x, startY, 8 * cellSize, color);

		// Draw horizontal lines
		uint16_t y = startY + i * cellSize;
		ILI9341_DrawHLine(startX, y, 8 * cellSize, color);
	}
	*/

	/* Draw the grid and fill
	for (uint16_t i = 0; i < 8; i++) {
		for (uint16_t j = 0; j < 8; j++) {
			// Calculate the position and dimensions of each rectangle
			uint16_t x = startX + i * cellSize;
			uint16_t y = startY + j * cellSize;
			uint16_t width = cellSize;
			uint16_t height = cellSize;

			// Draw the grid lines on top of the filled rectangles
			ILI9341_DrawRectangle(x, y, width, height, gridColor);

			// Fill each rectangle with the specified fill color
			ILI9341_DrawFilledRectangleCoord(x, y, x + width - 1V thickness, y + height - 1H thickness, fillColor);
		}
	}
	*/
}

/**
 * @brief Draw a character on the screen.
 * @param character The character to draw.
 * @param m_cellSize The size of each cell in the grid.
 * @param m_borderSpace The amount of border space to leave around each cell.
 * @param m_scalFactor The scale factor to adjust the cell size.
 */
void PixelArt_DrawCharacter(characterPixels8_8 character, uint8_t m_cellSize, uint8_t m_borderSpace, float m_scalFactor) {
	// if grid 0 || 1 ifndef ...

	// Define the size of each cell in the grid
	uint8_t cellSize = m_cellSize;

	uint8_t width = cellSize;
	uint8_t height = cellSize;

	// Scale the model according to a scale ratio
	if (m_scalFactor != 0)
		cellSize = (uint8_t)cellSize * m_scalFactor;

	// Define the position of the grid on the display
	uint16_t startX = (ILI9341_SCREEN_HEIGHT - 8 * cellSize) / 2;
	uint16_t startY = (ILI9341_SCREEN_WIDTH - 8 * cellSize) / 2;

	// Draw the character
	for (uint16_t i = 0; i < 8; i++) {
		for (uint16_t j = 0; j < 8; j++) {
			// Calculate the position and dimensions of each rectangle
			uint16_t x = startX + i * cellSize;
			uint16_t y = startY + j * cellSize;

			// Fill each rectangle with the specified color
			uint16_t color = character.pixels[i][j];
			ILI9341_DrawFilledRectangleCoord(x, y, x + width - m_borderSpace, y + height - m_borderSpace, color);
		}
		HAL_Delay(100);
	}
}

/**
 * @brief Animate a sequence of characters on the screen.
 * @param character An array of characters to animate.
 * @param m_cellSize The size of each cell in the grid.
 * @param m_borderSpace The amount of border space to leave around each cell.
 * @param m_scalFactor The scale factor to adjust the cell size.
 */
void PixelArt_AnimeCharacter(characterPixels8_8 character[4], uint8_t m_cellSize, uint8_t m_borderSpace, float m_scalFactor) {
	for (uint8_t i = 0; i < 4; ++i) {
		PixelArt_DrawCharacter(character[i], m_cellSize, m_borderSpace, m_scalFactor);
		// animation speed
	}
}

/**
 * @brief Perform a screen test by filling the screen with a color and displaying text.
 */
void PixelArt_ScreenTest() {
	ILI9341_Init();
	ILI9341_FillScreen(W);
	ILI9341_SetRotation(SCREEN_HORIZONTAL_2);
	ILI9341_DrawText("HELLO WORLD", FONT4, 90, 110, BL, W);
}
