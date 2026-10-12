/* Ghidra pseudocode, not original source.
 * ev_e349fb5d4996fa1cecd3bcddaaa967a101a71b87d72fe496b907a3d03e81288d
 * Entry: 0x60d9b0; label: FUN_0060d9b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_0060d9b0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  piVar4 = DAT_02856be8;
  local_4 = param_2;
  local_8 = 0;
  local_10 = 0;
  local_c = param_3;
  piVar3 = DAT_02856bec;
  if (DAT_02856bec < DAT_02856be8) {
    FUN_006e9fe6();
    piVar3 = DAT_02856bec;
  }
  while( true ) {
    piVar2 = piVar3;
    if (piVar3 < DAT_02856be8) {
      FUN_006e9fe6();
      piVar2 = DAT_02856bec;
    }
    if (piVar4 == piVar3) goto LAB_0060da48;
    if (piVar2 <= piVar4) {
      FUN_006e9fe6();
      piVar2 = DAT_02856bec;
    }
    if (piVar4[1] == local_4) break;
    if (piVar2 <= piVar4) {
      FUN_006e9fe6();
      piVar2 = DAT_02856bec;
    }
    piVar4 = piVar4 + 2;
    piVar3 = piVar2;
  }
  if (piVar2 <= piVar4) {
    FUN_006e9fe6();
  }
  local_8 = *piVar4;
  local_4 = piVar4[1];
LAB_0060da48:
  if (local_8 == 0) {
    FUN_006e4870(local_4,&local_8);
    FUN_0060d890(&local_8);
  }
  piVar4 = DAT_02856bf8;
  piVar3 = DAT_02856bfc;
  if (DAT_02856bfc < DAT_02856bf8) {
    FUN_006e9fe6();
    piVar3 = DAT_02856bfc;
  }
  while( true ) {
    piVar2 = piVar3;
    if (piVar3 < DAT_02856bf8) {
      FUN_006e9fe6();
      piVar2 = DAT_02856bfc;
    }
    if (piVar4 == piVar3) goto LAB_0060dae8;
    if (piVar2 <= piVar4) {
      FUN_006e9fe6();
      piVar2 = DAT_02856bfc;
    }
    if (piVar4[1] == local_c) break;
    piVar3 = piVar2;
    if (piVar2 <= piVar4) {
      FUN_006e9fe6();
      piVar3 = DAT_02856bfc;
    }
    piVar4 = piVar4 + 2;
  }
  if (piVar2 <= piVar4) {
    FUN_006e9fe6();
  }
  local_10 = *piVar4;
  local_c = piVar4[1];
LAB_0060dae8:
  if (local_10 == 0) {
    FUN_006e4770(local_c,&local_10);
    FUN_0060d920(&local_10);
  }
  iVar1 = local_8;
  if ((local_8 != 0) && (local_10 != 0)) {
    piVar4 = (int *)FUN_0060a150();
    *piVar4 = iVar1;
    piVar4[1] = local_10;
    return piVar4;
  }
  return (int *)0x0;
}

