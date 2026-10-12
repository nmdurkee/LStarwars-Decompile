/* Ghidra analysis pseudocode, not original source.
 * ev_14516b90afd78e4126f0b3f4a370dbc2a5912f8e0102dea09dbec3c8384d0f78
 * Entry: 0x6e3800; label: FUN_006e3800
 */

void FUN_006e3800(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_14;
  
  FUN_006069a0();
  FUN_005fb870(param_1,0,0);
  iVar2 = FUN_005f7c40(param_1);
  if (iVar2 == DAT_00973900) {
    iVar2 = FUN_005f7c50(param_1);
    if (iVar2 == DAT_00973904) {
      cVar1 = '\0';
      goto LAB_006e384b;
    }
  }
  cVar1 = '\x01';
LAB_006e384b:
  iVar2 = *(int *)(in_ECX + 0x6c4);
  if ((*(int *)(in_ECX + 0x638) != 0) || (iVar2 == 0)) {
    iVar2 = *(int *)(in_ECX + 0x6b0);
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x88))
            (*(int **)(in_ECX + 4),iVar2,0,local_14,0,cVar1 + '\x01');
  FUN_00606a20();
  return;
}

