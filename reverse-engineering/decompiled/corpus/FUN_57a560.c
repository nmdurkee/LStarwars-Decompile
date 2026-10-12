/* Ghidra analysis pseudocode, not original source.
 * ev_0fe45ae231fd2dfd40158a7785e6912069fa204ac07eb0ac56676de85047f6bb
 * Entry: 0x57a560; label: FUN_0057a560
 */

void FUN_0057a560(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(param_1 + 0x128) + 0x7c);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0057a575. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}

