/* Ghidra pseudocode, not original source.
 * ev_ebdcb732153d7bf306588444e9af2e40ea41c4dbebef89d348e04ae4a29830a2
 * Entry: 0x55a1b0; label: FUN_0055a1b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0055a1b0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if ((((DAT_0093b268 != (int *)0x0) && (param_1 != 0)) && (param_2 != 0)) &&
     (((int)(uint)*(byte *)(param_2 + 6) < *DAT_0093b268 &&
      (pcVar1 = *(code **)((uint)*(byte *)(param_2 + 6) * 0x9c + 0x48 + DAT_0093b268[2]),
      pcVar1 != (code *)0x0)))) {
    uVar2 = (*pcVar1)(param_2,param_3,param_4);
    return uVar2;
  }
  return 0;
}

