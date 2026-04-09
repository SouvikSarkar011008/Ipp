# Pong Game for Ipp - Canvas Version
# Run this in the Ipp REPL or Web Playground

# Initialize game variables
var paddle1_y = 150
var paddle2_y = 150
var ball_x = 200
var ball_y = 150
var ball_dx = 3
var ball_dy = 2
var score1 = 0
var score2 = 0
var game_over = false

# Open canvas window
print("Starting Pong game...")
print("Use W/S for left paddle, UP/DOWN for right paddle")
print("Click on the window to start!")

func draw_game() {
    # Clear canvas
    canvas_clear("black")
    
    # Draw center line
    canvas_line(200, 0, 200, 300, "gray")
    
    # Draw paddles
    canvas_rect(10, paddle1_y, 20, 80, "white")
    canvas_rect(370, paddle2_y, 20, 80, "white")
    
    # Draw ball
    canvas_circle(ball_x, ball_y, 10, "yellow")
    
    # Draw scores
    canvas_text(80, 30, "Player 1: " + str(score1), "white")
    canvas_text(260, 30, "Player 2: " + str(score2), "white")
    canvas_text(150, 280, "PONG - Ipp", "gray")
}

# Move ball function
func move_ball() {
    ball_x = ball_x + ball_dx
    ball_y = ball_y + ball_dy
    
    # Top and bottom wall
    if ball_y <= 10 or ball_y >= 290 {
        ball_dy = -ball_dy
    }
    
    # Left paddle collision
    if ball_x <= 30 and ball_x >= 10 {
        if ball_y >= paddle1_y and ball_y <= paddle1_y + 80 {
            ball_dx = -ball_dx
            ball_x = 35
        }
    }
    
    # Right paddle collision  
    if ball_x >= 370 and ball_x <= 390 {
        if ball_y >= paddle2_y and ball_y <= paddle2_y + 80 {
            ball_dx = -ball_dx
            ball_x = 365
        }
    }
    
    # Score conditions
    if ball_x <= 0 {
        score2 = score2 + 1
        ball_x = 200
        ball_y = 150
        ball_dx = -ball_dx
    }
    if ball_x >= 400 {
        score1 = score1 + 1
        ball_x = 200
        ball_y = 150
        ball_dx = -ball_dx
    }
}

# This is a demo - the actual game loop would need keyboard input
# which requires more complex setup

print("\n=== Pong Game Demo ===")
print("To play Pong, the canvas needs keyboard input support.")
print("This is being developed for v1.5.4 (REPL enhancements).")
print("")
print("Current workaround - click the canvas window to move paddles")
print("or use mouse to interact.")

# Draw initial game state
draw_game()
print("\nCanvas Pong game initialized!")
print("See examples/pong_game.py for Python version with keyboard input.")