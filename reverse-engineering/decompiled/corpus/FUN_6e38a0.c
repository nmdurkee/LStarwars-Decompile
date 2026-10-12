/* Ghidra analysis pseudocode, not original source.
 * ev_14516b90afd78e4126f0b3f4a370dbc2a5912f8e0102dea09dbec3c8384d0f78
 * Entry: 0x6e38a0; label: FUN_006e38a0
 */

void FUN_006e38a0(undefined4 param_1)

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
      goto LAB_006e38eb;
    }
  }
  cVar1 = '\x01';
LAB_006e38eb:
  (**(code **)(**(int **)(in_ECX + 4) + 0x88))
            (*(int **)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x6e8),0,local_14,0,cVar1 + '\x01');
  FUN_00606a20();
  return;
}

