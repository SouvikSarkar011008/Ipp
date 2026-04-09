#!/usr/bin/env python3
"""Pong Game using Ipp Canvas - Python wrapper for Ipp canvas functions."""

import tkinter as tk
import sys

# Import Ipp canvas functions
sys.path.insert(0, '.')
try:
    from ipp.runtime.canvas import ipp_canvas_open, ipp_canvas_rect, ipp_canvas_circle
    from ipp.runtime.canvas import ipp_canvas_line, ipp_canvas_text, ipp_canvas_clear
    has_canvas = True
except:
    has_canvas = False


class PongGame:
    def __init__(self):
        self.window = tk.Tk()
        self.window.title("Pong - Ipp Canvas")
        self.window.geometry("400x320")
        self.window.bind('<Key>', self.on_key)
        
        self.canvas = tk.Canvas(self.window, bg="black", width=400, height=300)
        self.canvas.pack()
        
        # Game variables
        self.paddle1_y = 110
        self.paddle2_y = 110
        self.ball_x = 200
        self.ball_y = 150
        self.ball_dx = 3
        self.ball_dy = 2
        self.score1 = 0
        self.score2 = 0
        
        self.draw()
        self.update()
        self.window.mainloop()
    
    def draw_rect(self, x, y, w, h, color):
        self.canvas.create_rectangle(x, y, x+w, y+h, fill=color, outline=color)
    
    def draw_circle(self, x, y, r, color):
        self.canvas.create_oval(x-r, y-r, x+r, y+r, fill=color, outline=color)
    
    def draw_line(self, x1, y1, x2, y2, color):
        self.canvas.create_line(x1, y1, x2, y2, fill=color, width=2)
    
    def draw_text(self, x, y, text, color):
        self.canvas.create_text(x, y, text=text, fill=color, font=("Arial", 12))
    
    def clear(self, color):
        self.canvas.delete("all")
        self.canvas.config(bg=color)
    
    def draw(self):
        self.clear("black")
        self.draw_line(200, 0, 200, 300, "gray")
        self.draw_rect(10, self.paddle1_y, 20, 80, "white")
        self.draw_rect(370, self.paddle2_y, 20, 80, "white")
        self.draw_circle(self.ball_x, self.ball_y, 10, "yellow")
        self.draw_text(80, 20, f"P1: {self.score1}", "white")
        self.draw_text(280, 20, f"P2: {self.score2}", "white")
        self.draw_text(150, 290, "PONG - Ipp Canvas", "gray")
    
    def on_key(self, event):
        key = event.keysym.lower()
        if key == 'w' and self.paddle1_y > 0:
            self.paddle1_y -= 20
        if key == 's' and self.paddle1_y < 220:
            self.paddle1_y += 20
        if key == 'up' and self.paddle2_y > 0:
            self.paddle2_y -= 20
        if key == 'down' and self.paddle2_y < 220:
            self.paddle2_y += 20
        self.draw()
    
    def update(self):
        self.ball_x += self.ball_dx
        self.ball_y += self.ball_dy
        
        if self.ball_y <= 10 or self.ball_y >= 290:
            self.ball_dy = -self.ball_dy
        
        if 10 <= self.ball_x <= 30 and self.paddle1_y <= self.ball_y <= self.paddle1_y + 80:
            self.ball_dx = -self.ball_dx
            self.ball_x = 35
        
        if 370 <= self.ball_x <= 390 and self.paddle2_y <= self.ball_y <= self.paddle2_y + 80:
            self.ball_dx = -self.ball_dx
            self.ball_x = 365
        
        if self.ball_x <= 0:
            self.score2 += 1
            self.ball_x = 200
            self.ball_y = 150
            self.ball_dx = 3
        
        if self.ball_x >= 400:
            self.score1 += 1
            self.ball_x = 200
            self.ball_y = 150
            self.ball_dx = -3
        
        self.draw()
        self.window.after(20, self.update)


if __name__ == "__main__":
    print("Starting Pong Game...")
    print("Controls: W/S for Player 1, UP/DOWN for Player 2")
    print()
    game = PongGame()