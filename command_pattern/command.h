/****************************************************************************************
* ALI SAHBAZ
*
*
* MY DESIGN PATTERNS WORKSHOP
*
* Date          : 17.02.2024
* By            : Ali Þahbaz
* e-mail        : ali_sahbaz@outlook.com
*/
#ifndef __COMMAND_H
#define __COMMAND_H

class shape_command
{
public:

	shape_command() = default;

	virtual ~shape_command() = default;

	virtual void draw() const = 0;

};

#include <memory>
#include <stack>

class shapes_manager
{
public:
	void compute(std::unique_ptr<shape_command> command) {
		command->draw( );
		stack_.push(std::move(command));
	}
	   
	void clear()
	{
		CommandStack{}.swap(stack_);
	}

private:

	using CommandStack = std::stack<std::unique_ptr<shape_command>>;
	 
	CommandStack stack_;
};



#endif 