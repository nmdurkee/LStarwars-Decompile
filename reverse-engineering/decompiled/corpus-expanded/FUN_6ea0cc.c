/* Ghidra pseudocode, not original source.
 * ev_7917d444e56ee151ebe44b68491c815c9234e24f7023aa905c57d397c47edbbf
 * Entry: 0x6ea0cc; label: _JumpToContinuation
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    void __stdcall _JumpToContinuation(void *,struct EHRegistrationNode *)
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

void _JumpToContinuation(void *param_1,EHRegistrationNode *param_2)

{
  undefined4 *unaff_FS_OFFSET;
  
  *unaff_FS_OFFSET = *(undefined4 *)*unaff_FS_OFFSET;
                    /* WARNING: Could not recover jumptable at 0x006ea0f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_1)();
  return;
}

