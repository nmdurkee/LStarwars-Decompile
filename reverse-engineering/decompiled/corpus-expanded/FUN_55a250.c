/* Ghidra pseudocode, not original source.
 * ev_ebdcb732153d7bf306588444e9af2e40ea41c4dbebef89d348e04ae4a29830a2
 * Entry: 0x55a250; label: FUN_0055a250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055a250(int param_1,int param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  
  if ((((DAT_0093b268 != (int *)0x0) && (param_1 != 0)) && (param_2 != 0)) &&
     (((int)(uint)*(byte *)(param_2 + 6) < *DAT_0093b268 &&
      (iVar3 = (uint)*(byte *)(param_2 + 6) * 0x9c, iVar1 = iVar3 + DAT_0093b268[2],
      *(int *)(iVar3 + 0x54 + DAT_0093b268[2]) != 0)))) {
    if ((param_3 != 0) && (pcVar2 = *(code **)(iVar1 + 0x5c), pcVar2 != (code *)0x0)) {
      (*pcVar2)(param_2,1);
    }
    (**(code **)(iVar1 + 0x54))(param_2,param_3);
  }
  return;
}

