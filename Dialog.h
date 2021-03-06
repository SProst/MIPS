#ifndef Dialog_h
#define Dialog_h

enum DialogTypes
{
  D_MENU,
  D_DIALOG,
  D_TITLE,                      // Display only the title
  D_INT,
  D_FLOAT,
  D_BINARY8,
  D_YESNO,
  D_ONOFF,
  D_FWDREV,
  D_FUNCTION,
  D_LIST,                       // Select from a list of options
  D_OFF                         // This will turn an entry off, it will be ignored
};

typedef struct
{
  char        *Name;            // Dialog box entry text
  int8_t      X,Y;              // Dialog box entry location
  DialogTypes Type;             // Entry type
  float       Min;
  float       Max;
  float       StepSize;
  int8_t      Xpos;             // X offset for entry location for data display
  bool        NoEdit;           // Flag set to true if field is not editable
  char        *fmt;             // Printf format string for display
  void        *Value;           // Pointer to value data as appropriate
  void (*PreFunction)(void);    // Pointer to function called when entry is selected
  void (*PostFunction)(void);   // Pointer to function called after value entry
}DialogBoxEntry;

typedef struct
{
  Window          w;
  MenuState       State;          // State of DialogBox 
  int8_t          Selected;       // Defines the selected enrty, -1 if not selection
  DialogBoxEntry  *Entry;         // Array of Dialog box entries, terminated with NULL
}DialogBox;

extern DialogBox *ActiveDialog;

// Prototypes
void DialogBoxProcessChange(DialogBox *d, int8_t change);
void DialogButtonPress(DialogBox *d);
void DialogValueAdjust(DialogBox *d,int8_t change);
void DialogBoxAdjust(DialogBox *d,int8_t change);
void DisplayDialogEntry(Window *w, DialogBoxEntry *de, bool HighLight);
void UpdateNoEditDialogEntries(Window *w, DialogBoxEntry *de);
void UpdateNoEditDialogEntries(DialogBox *d);
void DisplayAllDialogEntries(DialogBox *d);
void DisplayDialogEntryNames(Window *w, DialogBoxEntry *de, bool HighLight);
void DisplayAllDialogEntryNames(DialogBox *d);
void DialogBoxDisplay(DialogBox *d);

#endif


