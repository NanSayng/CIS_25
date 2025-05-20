--------
.H FILES
--------

	==========================
	****** File: user.h ******
	==========================

	1. Overview:
		- Declares core data model for the program: 'User', 'Meals', and 'Workouts' structs
		- Tracks personal user info (name, age, height, weight, gender, goals), daily calorie needs, and logged meals/workouts

	2. Style:
		- Consistent naming and use of 'vector<string>' and 'vector<double>' for tracking lists
		- Clear structure and readable layout
		- Minor typo in comment: "stroe" -> "store"

	3. Efficiency:
		- Good use of dynamic arrays via 'vector'
		- Struct of vectors may be less intuitive than vector of structs for some operations
		- Minimal boilerplate, clean and focused header

	4. Suggestions:
		- Consider renaming ambiguous fields like 'goal' (eg. 'goalType')
		- Could merge 'Meals' and 'Workouts' into a generic template or base structure if you want to reduce duplication
		- Add brief comments above each struct for clarity/future maintainability


	==========================
	****** File: menu.h ******
	==========================

	1. Overview:
		- Declares high-level user interface functions: display main menu, show user progress, and exit behavior
		- Tightly tied to user-facing console interaction

	2. Style:
		- Function names are descriptive
		- Commenting is minimal but clear
		- Consistent use of includes and header guards

	3. Efficiency:
		- Only declares functions - no major performance concerns
		- Might include more headers than needed (eg. 'iomanip')

	4. Suggestions:
		- Consider breaking display-only functions into a 'ui.h' if project grows
		- Rename 'viewProgress()' to something more specific like 'displayProgressReport()' for clarity


	=================================
	****** File: mealManager.h ******
	=================================

	1. Overview:
		- Declares user-facing functions for meal tracking: adding, removing, and displaying meals
		- Interacts heavily with the 'User' struct's 'Meals' data

	2. Style:
		- Clear, descriptive function names
		- Logical grouping of related functions
		- Clean formatting and no typos

	3. Efficiency:
		- Smart use of 'User&' to modify state in place
		- No apparent redundancy in interface, assuming validation logic is reused

	4. Suggestions:
		- Consider merging similar display logic with 'trackWorkouts()' via a shared helper
		- Brief docstring-style comments could help clarify function intent (mutates vs. displays)

	=====================================
	****** File: inputValidation.h ******
	=====================================

	1. Overview:
		- Declares validation helpers to ensure user inputs match expected formats (string, int, double, char)
		- Uses regex matching to enforce format constraints

	2. Style:
		- Clear function names that reflect behavior
		- Slightly confusing internal naming (eg. 'validateDouble' checks integers/spaces?)
		- Typo in comment: "spacees" -> "spaces"

	3. Efficiency:
		- Likely re-parsing regex in each call - might improve by using static const regex patterns
		- Simple and low-overhead functions

	4. Suggestions:
		- Improve or clarify comment descriptions (some are misleading)
		- Consider consolidating with templated or parameterized validation helper
		- Use 'const regex&' in implementation for efficiency

	=================================
	****** File: getUserInfo.h ******
	=================================

	1. Overview:
		- Declares main user data entry interface: gets name, age, gender, height, weight, goals, and activity level
		- Contains 'getMenuOption()' dispatcher and main 'getUserInfo()' orchestration function

	2. Style:
		- Clear and consistent naming of each 'getValidX()' function
		- Comments are minimal but help orient the reader
		- Header includes many other components - potentially a little heavy

	3. Efficiency:
		- Logical to separate each input type into its own validator
		- Could introduce a common reusable 'getValidatedInput()' function if logic is repeated

	4. Suggestions:
		- Add brief comments above functions specifying return expectations and edge cases
		- Refactor shared patterns (prompt → validate → convert) to reduce boilerplate
		- Consider moving menu logic into its own 'menuController.h' if project grows

	====================================
	****** File: fitnessManager.h ******
	====================================

	1. Overview:
		- Declares functions related to workouts and fitness metrics (BMR, TDEE, calorie goals)
		- Tied closely to user's fitness journey and progress tracking

	2. Style:
		- Function names are descriptive and match expected behavior
		- Comments are minimal but sufficient
		- Logical grouping of workout + calculation utilities

	3. Efficiency:
		- Function separation is good: one function = one responsibility
		- If 'calculateTDEE()' or 'calculateDailyCalorie()' are called frequently, caching might help if values don’t change

	4. Suggestions:
		- Consider more precise naming for 'trackWorkouts()' (eg. 'displayWorkouts()' if that’s all it does)
		- Separate workout logic and calorie math into different files for better cohesion
		- Add comment clarifying whether BMR is calculated via Mifflin-St Jeor, Harris-Benedict, etc.



----------
.CPP FILES
----------

	============================
	****** File: main.cpp ******
	============================

	1. Overview:
		- This file is the entry point for the fitness tracker program. Initializes user data, launches menu system

	2. Functionality:
		- Works as expected
		- Is lightweight, calls functions as appropriate

	3. Structure:
		- Simple and expandable
		- Calls the primary functions which, in turn, call other needed functions
		- Defines User as a global variable

	4. Style:
		- Clean menu formatting
		- Consistent naming conventions

	5. Clarity:
		- Very clear commenting, there are no mysteries to unravel

	6. Efficiency:
		- No notes. File is short enough to have no efficiency issues

	7. Testing:
		- No unit tests for main.cpp (Hard to test I/O)

	8. Suggestions:
		- Eliminate global User; declare in main() and pass by reference
		- Wrap main() in try-catch for graceful error handling
		- Optional: add a Help flag for command line usage

	9. Bugs:
		- Global User variable risks corruption
		- No input validation in main() - instead it's delegated to getUserInfo()


	============================
	****** File: menu.cpp ******
	============================

	1. Overview:
		- This file handles user interaction through the main menu, progress display, and exit confirmation
		- The file name matches its content
		- It is UI-oriented and tightly handles user I/O

	2. Functionality:
		- displayMainMenu() correctly prints out options
		- viewProgress() aggregates meal and workout calories, compares them to user's goal. Seems functionally complete.
		- exitProgram() handles exit confirmation smoothly

	3. Structure:
		- Most functions are single-purpose and self-contained
		- viewProgress() handles a lot - consider breaking down into smaller functions or adding helper functions external to viewProgress
		- No namespace used. Not an issue, only an observation

	4. Style:
		- Formatting is mostly fine, save for a few points:
			* Inconsistent newline spacing in viewProgress()
			* Some comments explain self-explanatory code (eg. progress title)
			* Typo on line 72 (progream -> program)
		- Variable naming conventions are consistent throughout

	5. Clarity:
		- Code is logical and intent is clear
		- Could benefit from function-level comments to outline what each function broadly does, especially if viewProgress() is broken down to smaller functions
		- Control flow in viewProgress() and exitProgram() are readable but pretty far nested.

	6. Efficiency:
		- No performance issues detected. All operations are simple aggregates or I/O.
		- If the calorie vectors are huge, summing them might be computationally expensive. Strongly doubt this will be an issue, just thinking on a maximum-possible scale.

	7. Testing:
		- This file drives UI, no unit tests are given
		- Some tests could be written if calorie aggregation were separated from other logic

	8. Suggestions:
		- Break viewProgress() into smaller functions for increased modularity and to facilitate testing of logic
			* One for calorie computation
			* One for the display logic
			* One for input prompt
		- Consider a wrapper like returnToMenu(user) instead of repeated displayMainMenu() and getMenuOption(user) calls
		- Fix minor spelling issue and consistent newline character usage
		- Add comment blocks to explain an overview of each function in addition to robust inline comments
		- If scalability is the goal, consider a UI handler instead of raw cin/cout logic

	9. Bugs:
		- No explicit bugs detected


	=======================================
	****** File: inputValidation.cpp ******
	=======================================

	1. Overview:
		- This file is simple: it defines input validation functions based on expected input type
		- The file name matches its content

	2. Functionality:
		- Each function serves a singular, clear purpose and uses regular expressions to validate input formats
		- All functions return boolean, making them easy to use for validating input with cin

	3. Structure:
		- Simple and well-structured
		- Each function is short, automatic, and independently testable
		- Consider grouping these into one namespace to avoid name collisions in large databases

	4. Style:
		- Clean and readable
		- Few minor typos:
			* line 9 "spacees"
			* string input contain -> string input contains

	5. Clarity:
		- Intent is clear
		- Function names can be interpreted as slightly misleading: they don't validate the data types themselves, but rather the string inputs *before* parsing to their respective data types
			* Functionally identical, just a minor nomenclature gripe

	6. Efficiency:
		- Efficient and fast
		- At large scale, compiled regex objects could be reused instead of re-declared for each function call

	7. Testing:
		- No unit test cases found for this file (each function can and should be tested)
		- Edge cases:
			* validateDouble() rejects leading zeroes - not hugely problematic but users might not expect that behavior
			* validateInt() accepts string inputs of digits, but should trim whitespace at some point
			* validateString() accepts an empty string or a string of only spaces; users might expect this to be rejected

	8. Suggestions:
		- Improve naming clarity to reflect that these functions operate on strings before parsing
		- Fix minor typos in comments
		- Add small comment blocks for each function describing an overview of each one as well as examples of valid/invalid input
		- Include unit tests for each function
		- Use static regex to avoid recompiling on every call

	9. Bugs:
		- No major bugs detected
		- validateDouble() will not accept input like "0." or "0.0" if you expect a float but do not allow trailing decimals.
		- Blank input or all space string inputs accepted by validateString() may cause isues down the line


	=======================================
	****** File: mealManager.cpp ******
	=======================================

	1. Overview:
		- Handles logic for adding, removing, and tracking user meals
		- Interacts with user input and updates the user.meals struct accordingly
		- Loops back into the main menu flow after each operation

	2. Functionality:
		- addMeal() prompts for a meal name and calorie count, validates both, and appends them to the user's vectors
		- removeMeals() lists existing meals and allows user to remove one by index, with input validation and post-removal logic
		- trackMeals() displays meals and optionally redirects user to add more
		- Each function loops back to the main menu or recursively re-calls itself for continued user interaction

	3. Structure:
		- Structure is procedural but logically sound
		- Some reuse via recursion (removeMeals() calls itself)
		- All functions are standalone and rely on user input; could be restructured to separate logic and I/O
		- Repeated patterns (menu display, asking for yes/no, printing meal list) could be abstracted into helper functions

	4. Style:
		- Generally readable
		- Inconsistent spacing in blocks (some closing braces on same line, some not)
		- Typos:
			* "diplay" (should be "display")
			* "user have" (should be "user has")
		- Minor naming mismatch: variables like input1, input2 are non-descriptive

	5. Clarity:
		- Behavior is clear from reading code
		- Heavy reliance on string input for numeric values (eg. meal index) makes sense in context of validation, but adds verbosity
		- Could benefit from comments in blocks showing the main loop flow at a higher level
		- Display blocks could be abstracted out for simplicity

	6. Efficiency:
		- No major issues with efficiency
		- Calls to stod() and stoi() after regex validation are reasonably safe but still throw exceptions if misused
		- Recompiling regex isn't an issue here since it's offloaded to the validation functions
		- Recursion in removeMeals() is functionally fine but stack-unsafe if users keep removing meals indefinitely (unlikely in practice)

	7. Testing:
		- No unit tests found
		- Edge cases to test:
			* Adding meals with trailing or leading spaces
			* Removing from an empty list
			* Entering out-of-range meal numbers
			* Entering non-numeric strings as meal indexes
			* Typing capital letters or invalid characters when prompted with yes/no questions

	8. Suggestions:
		- Abstract meal list printing into a printMeals() function to reduce duplication
		- Consolidate repeated user prompts (eg. "Would you like to add/remove another meal?") into a helper function
		- Use descriptive variable names instead of input1, input2, etc.
		- Consider breaking out I/O from the core logic to enable unit testing
		- Add try-catch around stod / stoi for safety, even with validation
		- Introduce helper like returnToMainMenu(user) to avoid repeated displayMainMenu() / getMenuOption(user) pairs

	9. Bugs:
		- No critical bugs detected
		- Potential crash if stod() or stoi() throws on unexpected input despite validation
		- Mixing cin.ignore() and getline() without cleaning cin can lead to skipped input
		- Recursive calls in removeMeals() could theoretically stack overflow, though it's an edge case


	=======================================
	****** File: getUserInfo.cpp ******
	=======================================

	1. Overview:
		- This file handles all user input prompts to collect and validate profile data (name, age, gender, height, weight, goals)
		- 'getUserInfo()' uses a step-by-step process using multiple helper functions
		- Includes menu navigation with getMenuOption()

	2. Functionality:
		- Each getValidX() function prompts, validates, and converts input
		- Validation is delegated to external functions like validateInt(), validateDouble(), and validateString()
		- getMenuOption() maps user input [1–8] to corresponding program features via a switch statement

	3. Structure:
		- Well-modularized: each validation concern is isolated to its own function
		- Shared patterns (prompt, regex validate, convert) are repeated across functions; could be reduced with templates or lambdas
		- getUserInfo() is a clear, linear pipeline with no branching logic - easy to follow

	4. Style:
		- Readable, but inconsistent formatting in some places (mixed brace styles, else sometimes on same line, sometimes not)
		- Several typos:
			* "user have" -> "user has"
			* "diplay" -> "display"
			* "datas" -> "data"
			* Missing ')' in line 246 ("6–7 days exercise per week") -> unbalanced parentheses
		- Variable naming is consistent, but occasional vague naming (input, reg) could be improved slightly for clarity

	5. Clarity:
		- Intent is easy to follow
		- All prompts are clear to users
		- Gender handling returns a boolean (isMale) - functionally fine, but may limit extensibility (eg. non-binary or "prefer not to say" cases)
		- Menu navigation logic is intuitive and safe due to input validation

	6. Efficiency:
		- Good use of regex and minimal logic per function
		- Repetitive recompilation of regex patterns inside each function (eg. regex reg(...)) could be avoided by making them static or reusing shared patterns
		- Uses getline() and cin inconsistently - mixing the two without cin.ignore() can cause input issues

	7. Testing:
		- No unit tests present
		- Edge cases to test:
			* Name: whitespace-only, hyphenated names, very long names
			* Age: 0, letters, symbols
			* Gender: non-m/F inputs, empty, spaces
			* Weights/heights: decimals with leading zeroes, negative values
			* Menu: invalid numbers or keyboard spam

	8. Suggestions:
		- Replace repetitive validation loops with a reusable helper (eg. getValidatedInput(prompt, regex, parser))
		- Consider improving gender handling to allow for broader options
		- Add comments before each function describing expected input/output and edge behavior
		- Fix input system to either always use getline() or consistently clean up cin buffer between uses
		- Declare regex constants at file scope or inside functions as static const to avoid recompilation
		- Improve prompt clarity slightly (eg. "Enter your name" -> "Please enter your full name")

	9. Bugs:
		- Mixed use of cin and getline() without flushing input stream may cause skipped prompts
		- Unbalanced parenthesis in getValidActiveLevel() (missing ')' in cout message for option 4)
		- If input is copy-pasted or malformed (eg. " 3" or "1\n2"), regex_match may silently reject or behave oddly


	=======================================
	****** File: fitnessManager.cpp ******
	=======================================

	1. Overview:
		- Manages workout tracking functionality for a user: adding, removing, viewing workouts, and calculating calorie metrics
		- Functions include addWorkout(), removeWorkouts(), trackWorkouts(), and calorie-related calculations
		- Relies on the User object structure (user.workouts, user.age, etc.) and uses helper validation and menu functions

	2. Functionality:
		- addWorkout() gathers workout name and calories with validation, allows multiple entries
		- removeWorkouts() displays a numbered list and lets the user remove specific entries by index
		- trackWorkouts() summarizes current entries and offers to add more
		- Calorie logic (calculateBMR, calculateTDEE, calculateDailyCalorie) uses standard health formulas

	3. Structure:
		- Loops and control flow are clear and user-driven via do/while and while loops
		- Input validation is consistent across functions, albeit slightly repetitive
		- Uses recursion for removeWorkouts() re-entry instead of looping - could lead to deep call stacks
		- Calls to displayMainMenu() and getMenuOption() are hard-coded at the end of most flows

	4. Style:
		- Brace style is consistent, but some mixed formatting (some 'else' on new line, some inline)
		- Several typos in comments:
			* "meal" instead of "workout" in multiple places
			* "diplay" -> "display"
			* "add workout" -> "add a workout" (missing article)
			* "You haven't add any workouts yet." -> "You haven't added any workouts yet."
		- Variable names are readable, though generic names like 'input1', 'input2' could be improved

	5. Clarity:
		- Overall logic is easy to follow for both users and readers
		- User prompts are straightforward, though sometimes slightly awkward grammatically
		- Calorie output message ("To be able to...") could be phrased more naturally
		- BMR/TDEE formulas are readable, and the intent is well communicated in comments

	6. Efficiency:
		- Repeated calls to size(user.workouts.workout) - could store once in a local variable
		- Redundant validation (eg. checking if 'calories.empty()' AND '!validateDouble(calories)')
		- No exception safety around stod()/stoi(), though validation is meant to prevent bad input
		- User prompts could be consolidated with a helper function to reduce repetition

	7. Testing:
		- No formal tests present
		- Edge cases to consider:
			* Deleting workout from empty list
			* Adding a workout with only whitespace or numbers in name
			* Entering calories as a negative number, 0, or with trailing junk (eg. "100abc")
			* BMR calculation for edge users (eg. age 0, height 0)
			* Activity level out of range (though default case handles it with exception)

	8. Suggestions:
		- Replace recursive calls in removeWorkouts() with loop-based control flow
		- Wrap cin >> input + getline patterns with reusable functions to avoid stale input issues
		- Move calorie calculation logic (TDEE, BMR) to a fitnessUtils.cpp or similar to separate I/O and computation
		- Create a generic prompt-and-validate loop function to eliminate duplicated code
		- Fix all lingering "meal" references in both code and comments
		- Improve prompt grammar for polish (eg. "Would you like to add workout?" -> "Would you like to add a workout?")

	9. Bugs:
		- 'cin.ignore()' is used unconditionally before 'getline()' - can skip prompts or consume input unexpectedly
		- Calls to stod()/stoi() are not wrapped in try/catch - user input could still crash the program
		- validateChar() doesn't show accepted values (eg. "Please enter 'y' or 'n'") - makes troubleshooting harder
		- Missing return path in calculateDailyCalorie() if user.goal is invalid - could return uninitialized garbage
		- Spacing bug in removeWorkouts() message: "There's only Xworkouts added." (missing space)