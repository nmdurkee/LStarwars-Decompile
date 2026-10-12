/* Ghidra pseudocode, not original source.
 * ev_ebdcb732153d7bf306588444e9af2e40ea41c4dbebef89d348e04ae4a29830a2
 * Entry: 0x55a120; label: FUN_0055a120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0055a120(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  
  if ((((DAT_0093b268 != (int *)0x0) && (param_1 != 0)) &&
      ((int)(uint)*(byte *)(param_1 + 6) < *DAT_0093b268)) &&
     (UNRECOVERED_JUMPTABLE =
           *(code **)((uint)*(byte *)(param_1 + 6) * 0x9c + 0x44 + DAT_0093b268[2]),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0055a14f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)();
    return uVar1;
  }
  return 0;
}

