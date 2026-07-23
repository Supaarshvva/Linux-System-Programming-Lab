# Recovery of Unsaved Work in `vi`

## Scenario

A software developer is editing a critical configuration file using `vi`.
Before the file is saved, the system crashes. The developer now wants to recover the work.

Below is a simple comparison of the main recovery mechanisms.

## 1. Swap files

### What it is

A swap file is a temporary file created by `vi` to store the current editing state.
It is usually created automatically while the file is being edited.

### How it helps in recovery

If the system crashes, the swap file still contains the latest changes that were not yet saved.
The developer can use recovery commands to restore the unsaved content.

### Advantages

- Best option for recovering unsaved work after a crash
- Stores the current editing buffer, not just the old saved version
- Works well for emergencies when the system goes down unexpectedly

### Limitations

- It depends on the editor creating and keeping the swap file
- The swap file may be lost if the system is restarted badly or the file is deleted
- The user must know the correct recovery command

## 2. Undo history

### What it is

Undo history is the list of recent changes made during the editing session.
It allows the user to move backward through edits.

### How it helps in recovery

If the file was edited recently and the editor is still running, undo can reverse the last changes.

### Advantages

- Very useful for small mistakes made during normal editing
- Easy to use for step-by-step reversal of edits

### Limitations

- It does not protect against sudden crashes
- It only keeps changes in the current session
- If the system is lost, the undo history may also be lost

## 3. Registers

### What it is

Registers are temporary storage areas inside `vi` where text can be copied or yanked.

### How it helps in recovery

If the developer copied important text into a register before the crash, that text may still be recoverable.

### Advantages

- Good for storing small pieces of text temporarily
- Helps move or reuse important lines quickly

### Limitations

- Not designed as a system-level crash recovery method
- Only useful for small copied sections, not the full file state
- Data may be lost if the editor session ends unexpectedly

## 4. Backup files

### What it is

A backup file is a copy of the original file that was saved earlier.
It is usually created before an overwrite or update.

### How it helps in recovery

If the current file is damaged or the new version is wrong, the developer can restore the old backup version.

### Advantages

- Useful for restoring a previously saved version
- Easy to compare with the current file

### Limitations

- Backup files only contain the old saved copy, not the latest unsaved changes
- They do not help if the crash happened before the file was saved
- They are not a complete recovery mechanism for unsaved work

## 5. Auto-recovery

### What it is

Auto-recovery means the editor automatically tries to recover the work after an unexpected shutdown.
In `vi`, this usually happens through swap-file-based recovery.

### How it helps in recovery

When the editor restarts after a crash, it checks for an existing swap file and offers recovery options.

### Advantages

- Very convenient for the user
- Can restore work with little manual effort
- Reduces the risk of losing important edits

### Limitations

- It still depends on the swap file being present
- Recovery may fail if the swap file is not available or is corrupted
- It is helpful only if the editor is configured to perform this recovery automatically

## Comparison summary

- Swap files: best for recovering unsaved work after a crash
- Undo history: helpful for recent changes, but not reliable after a crash
- Registers: useful for temporary text copies, not full file recovery
- Backup files: restore older saved versions, not the latest unsaved edits
- Auto-recovery: useful, but it usually depends on swap-file recovery behind the scenes

## Best recommendation

The most reliable recovery strategy is the use of swap files, together with the editor's auto-recovery feature.

### Why this is the best choice

- `vi` creates a swap file while editing, so it can preserve the current work even if the system crashes
- The swap file contains the latest unsaved buffer state
- It is specifically designed for crash recovery
- Unlike undo history and registers, it is not limited to small recent changes
- Unlike backup files, it can recover the work that was not saved before the crash

## Final conclusion

For recovering unsaved work after a crash in `vi`, swap files are the most reliable method.
They are designed to store the current editing state and allow the user to recover the file after an unexpected shutdown.
That makes them the best choice for a Linux System Programming lab assignment on crash recovery.
