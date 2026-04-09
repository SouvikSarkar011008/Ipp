# Pong Game for Ipp - Terminal Version
# A simple ASCII pong game

# Initialize game state
var ball_x = 40
var ball_y = 12
var ball_dx = 1
var ball_dy = 1
var paddle1_y = 10
var paddle2_y = 10
var score1 = 0
var score2 = 0
var game_running = true

# Clear screen function
func clear_screen() {
    print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
}

# Draw the game board
func draw_board() {
    clear_screen()
    print("══════════════════════════════════════════════════════════")
    print("                      PONG - Ipp Language")
    print("══════════════════════════════════════════════════════════")
    print("")
    print("   Player 1: " + str(score1) + "          Player 2: " + str(score2))
    print("")
    
    # Draw each row
    for y in 0..25 {
        var line = ""
        
        # Left paddle area (columns 0-5)
        if y >= paddle1_y - 2 and y <= paddle1_y + 2 {
            if y == paddle1_y - 2 or y == paddle1_y + 2 or y == paddle1_y {
                line = line + "█"
            } else {
                line = line + "█"
            }
        } else {
            line = line + " "
        }
        
        # Middle area (columns 6-73)
        if y == 0 or y == 24 {
            # Top and bottom borders
            line = line + "──────────────────────────────────────────────────"
        } else if y == 12 {
            # Middle dotted line
            line = line + "──────────────┌──────────────┌──────────────"
        } else if y == ball_y {
            # Ball position
            var spaces = ball_x - 6
            for s in 0..spaces {
                line = line + " "
            }
            line = line + "●"
        } else {
            # Empty middle space
            line = line + "                                    "
        }
        
        # Right paddle area (columns 74-79)
        if y >= paddle2_y - 2 and y <= paddle2_y + 2 {
            line = line + "█"
        } else {
            line = line + " "
        }
        
        print(line)
    }
    
    print("")
    print("══════════════════════════════════════════════════════════")
    print("Controls: W/S for Player 1, UP/DOWN for Player 2")
    print("Press Q to quit")
}

# Move ball
func move_ball() {
    ball_x = ball_x + ball_dx
    ball_y = ball_y + ball_dy
    
    # Top and bottom wall collision
    if ball_y <= 1 or ball_y >= 23 {
        ball_dy = -ball_dy
    }
    
    # Left paddle collision (paddle at x=5)
    if ball_x <= 6 {
        if ball_y >= paddle1_y - 2 and ball_y <= paddle1_y + 2 {
            ball_dx = -ball_dx
            ball_x = 7
        } else if ball_x <= 0 {
            # Score for player 2
            score2 = score2 + 1
            ball_x = 40
            ball_y = 12
            ball_dx = -ball_dx
        }
    }
    
    # Right paddle collision (paddle at x=74)
    if ball_x >= 73 {
        if ball_y >= paddle2_y - 2 and ball_y <= paddle2_y + 2 {
            ball_dx = -ball_dx
            ball_x = 72
        } else if ball_x >= 79 {
            # Score for player 1
            score1 = score1 + 1
            ball_x = 40
            ball_y = 12
            ball_dx = -ball_dx
        }
    }
}

# Game loop message
print("══════════════════════════════════════════════════════════════")
print("                    PONG - Ipp Language")
print("══════════════════════════════════════════════════════════════")
print("")
print("This is a simple demonstration of Ipp game capabilities.")
print("")
print("In the full version, you would be able to:")
print("  - Control paddles with keyboard input")
print("  - Have real-time ball physics")
print("  - Track scores between two players")
print("")
print("Current implemented features:")
print("  ✓ Canvas drawing (Tkinter window)")
print("  ✓ Canvas functions: rect, circle, line, text, clear")
print("  ✓ All previous Ipp features (functions, classes, etc.)")
print("")
print("To play a full interactive game, use the canvas in a GUI environment.")
print("")
print("Example canvas game code:")
print("  canvas_open()")
print("  canvas_clear('black')")
print("  canvas_rect(10, 50, 20, 80, 'white')  # Left paddle")
print("  canvas_rect(370, 50, 20, 80, 'white') # Right paddle")
print("  canvas_circle(200, 150, 10, 'white') # Ball")
print("  canvas_text(150, 280, 'PONG', 'white')")
print("")
print("══════════════════════════════════════════════════════════════")
print("See examples/pong_game.ipp for full canvas-based game!")
print("══════════════════════════════════════════════════════════════")