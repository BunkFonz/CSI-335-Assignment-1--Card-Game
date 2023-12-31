/*
Ildefonso Marrero
Last Modified: 11/7/2023
*/
#include "ActionCard.hpp"

/**
 @post: Construct a new Action Card object
**/
ActionCard::ActionCard(){
    CardType action_tmp = ACTION_CARD; //set the type to action card
    setType(action_tmp); //set the type
}

/**
    * @return true if the card is playable, false otherwise
    * For a card to be playable, it has to be drawn and the instruction has to be valid
    * Valid instructions:
    * DRAW x CARD(S) : assume x is a positive integer
    * PLAY x CARD(S) : assume x is a positive integer
    * REVERSE HAND : reverse the order of the cards in the hand
    * SWAP HAND WITH OPPONENT : swap the hand with the opponent
*/
bool ActionCard::isPlayable(){
    bool can_play = false; //initialize the bool to false
    if(getDrawn() == false || getInstruction() == ""){
        return can_play; //return false if the card is not drawn or the instruction is empty   
    }
    std::string instruction = getInstruction(); //get the instruction
    if(instruction == "REVERSE HAND" || instruction == "SWAP HAND WITH OPPONENT" || instruction.find("DRAW") != std::string::npos || instruction.find("PLAY") != std::string::npos){ //if the instruction is reverse hand or swap hand with opponent or draw or play
        can_play = true; //set the bool to true
    }
    return can_play; //return the bool
}

/**
    * @post: Print the ActionCard in the following format:
    * Type: [CardType]
    * Instruction: [Instruction]
    * Card: 
    * [ImageData]
    * 
    * Note: For [ImageData]: If there is no image data, print "No image data" instead
*/
void ActionCard::Print() const{
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Instruction: " << getInstruction() << std::endl;
    std::cout << "Card: " << std::endl;
    if(getImageData() == nullptr){
        std::cout << "No image data" << std::endl;
    }else{
        for(int i = 0; i < 80; i++){
            std::cout << getImageData()[i] << " ";
        }
        std::cout << std::endl;
    }
    
}