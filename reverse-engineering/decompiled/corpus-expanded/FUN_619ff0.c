/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x619ff0; label: FUN_00619ff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00619ff0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int in_ECX;
  int in_EDX;
  undefined2 local_108 [2];
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_108;
  DAT_02912ed4 = DAT_02912ed4 + -1;
  local_108[0] = 0x40;
  if (DAT_02912ed4 < 1) {
    DAT_02912ed4 = DAT_0080f58c;
  }
  if (DAT_0080f58c >> 1 <= DAT_02912ed4) {
    iVar1 = FUN_004f1ff0();
    if (in_EDX == 0) {
      iVar2 = 0;
    }
    else {
      FUN_004f1f40(local_104);
      FUN_005d0d60(DAT_02912b38,local_104);
      iVar2 = FUN_006e6b90();
    }
    if (in_EDX < iVar1) {
      local_108[0] = CONCAT11(local_108[0]._1_1_,*(undefined1 *)(in_EDX + in_ECX));
    }
    else {
      local_108[0] = CONCAT11(local_108[0]._1_1_,0x41);
    }
    FUN_005d0d60(DAT_02912b38,local_108);
    uVar3 = FUN_006e6b90();
    FUN_005d0eb0(DAT_02912b38);
    iVar1 = FUN_006e6b90();
    FUN_005d0e80(DAT_02912b38);
    uVar4 = FUN_006e6b90();
    if (DAT_02912eb8 == 0) {
      FUN_005db880(iVar2 + param_1,param_2 - iVar1,uVar3,uVar4,param_3,0);
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_108);
  return;
}

