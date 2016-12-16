/* 
 * Copyright (C) 2014 Joseph
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
package control;

import java.awt.Color;
import java.awt.GridBagConstraints;
import java.awt.event.ActionEvent;

import javax.swing.JButton;
import javax.swing.JFrame;

import model.Board;
import model.Piece;
import model.PieceColor;
import model.PieceType;

/**
 *
 * @author Joseph
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Board board = new Board();
        JFrame frame = new JFrame("My chessboard");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().add(board);
        frame.setResizable(false);
        frame.pack();
        frame.setLocationByPlatform(true);
        frame.setVisible(true);                 
   
        
        board.getCustom_PossibleMoves(PieceType.KNIGHT, PieceColor.BLACK, "d7");

        
        /*board.getCustom_PossibleMoves(PieceType.KING, PieceColor.BLACK, "a4");
        board.getCustom_PossibleMoves(PieceType.PAWN, PieceColor.BLACK, "b5");
        board.getCustom_PossibleMoves(PieceType.ROOK, PieceColor.BLACK, "c7");
        board.getCustom_PossibleMoves(PieceType.QUEEN, PieceColor.BLACK, "e1");
        board.getCustom_PossibleMoves(PieceType.BISHOP, PieceColor.BLACK, "f3");
        board.getCustom_PossibleMoves(PieceType.ROOK, PieceColor.BLACK, "g2");
        board.getCustom_PossibleMoves(PieceType.PAWN, PieceColor.BLACK, "h8");
        
        board.getDistantPiece(PieceType.KNIGHT, PieceColor.WHITE, "d2");*/
        
    }
}
