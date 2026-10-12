/* Ghidra pseudocode, not original source.
 * ev_ebdcb732153d7bf306588444e9af2e40ea41c4dbebef89d348e04ae4a29830a2
 * Entry: 0x55a320; label: FUN_0055a320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0055a320(int param_1,int param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if ((((DAT_0093b268 != (int *)0x0) && (param_1 != 0)) && (param_2 != 0)) &&
     (((int)(uint)*(byte *)(param_2 + 6) < *DAT_0093b268 &&
      (pcVar1 = *(code **)((uint)*(byte *)(param_2 + 6) * 0x9c + 0x60 + DAT_0093b268[2]),
      pcVar1 != (code *)0x0)))) {
    uVar2 = (*pcVar1)(param_2);
    return uVar2;
  }
  return 0;
}

