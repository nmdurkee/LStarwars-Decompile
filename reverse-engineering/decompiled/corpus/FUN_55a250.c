/* Ghidra analysis pseudocode, not original source.
 * ev_7906274d0bf06d109a71291565ad9b380751ea78f5df54402dc74cb176b33c5a
 * Entry: 0x55a250; label: FUN_0055a250
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

