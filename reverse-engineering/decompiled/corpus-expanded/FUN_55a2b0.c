/* Ghidra pseudocode, not original source.
 * ev_ebdcb732153d7bf306588444e9af2e40ea41c4dbebef89d348e04ae4a29830a2
 * Entry: 0x55a2b0; label: FUN_0055a2b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055a2b0(int param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  
  if ((((DAT_0093b268 != (int *)0x0) && (param_1 != 0)) && (param_2 != 0)) &&
     (((int)(uint)*(byte *)(param_2 + 6) < *DAT_0093b268 &&
      (iVar2 = (uint)*(byte *)(param_2 + 6) * 0x9c + DAT_0093b268[2], *(int *)(iVar2 + 0x5c) != 0)))
     ) {
    if ((param_3 == 0) && (pcVar1 = *(code **)(iVar2 + 0x54), pcVar1 != (code *)0x0)) {
      (*pcVar1)(param_2,0);
    }
    (**(code **)((uint)*(byte *)(param_2 + 6) * 0x9c + 0x5c + DAT_0093b268[2]))(param_2,param_3);
  }
  return;
}

