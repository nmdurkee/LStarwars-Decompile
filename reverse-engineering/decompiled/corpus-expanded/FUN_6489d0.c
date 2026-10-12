/* Ghidra pseudocode, not original source.
 * ev_4cb705c119a92d6224ed1b3e942cece0f3f9eff485159b2837ae2ccadb058a2e
 * Entry: 0x6489d0; label: FUN_006489d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006489d0(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (DAT_02962114 == 0) {
    return 0xffffffff;
  }
  uVar1 = FUN_006488e0(param_1,DAT_02962114);
  return uVar1;
}

