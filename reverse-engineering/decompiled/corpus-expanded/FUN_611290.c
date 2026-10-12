/* Ghidra pseudocode, not original source.
 * ev_4979805bbb21a8904736e4a261aef1b5206e58d1861917e5f468ac2db6a4df52
 * Entry: 0x611290; label: FUN_00611290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00611290(int param_1)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int in_ECX;
  uint _NumOfElements;
  int local_40c [2];
  ushort local_404 [514];
  
  iVar3 = FUN_006179c0();
  uVar4 = FUN_00610690(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10),in_ECX + 0x40)
  ;
  *(undefined4 *)(in_ECX + 0x17b8) = uVar4;
  iVar5 = FUN_006179c0();
  iVar7 = *(int *)(in_ECX + 0x17b8);
  *(int *)(in_ECX + 0x1c0c) = *(int *)(in_ECX + 0x1c0c) + (iVar5 - iVar3);
  if (iVar7 < 0x4f1) {
    *(int *)(in_ECX + 0x19f4) = *(int *)(in_ECX + 0x19f4) + iVar7;
    *(int *)(in_ECX + 0x19fc) = *(int *)(in_ECX + 0x19fc) + 1;
    (**(code **)(*DAT_028572e0 + 0x58))(in_ECX + 0x40,iVar7,param_1 + 8);
    return iVar7;
  }
  *(int *)(in_ECX + 0x1c14) = *(int *)(in_ECX + 0x1c14) + 1;
  uVar1 = *(uint *)(param_1 + 0x10);
  _NumOfElements = 0;
  uVar6 = 0;
  if (uVar1 != 0) {
    do {
      if (0xff < _NumOfElements) break;
      _NumOfElements = _NumOfElements + 1;
      uVar2 = *(ushort *)(uVar6 + *(int *)(param_1 + 0xc));
      local_404[_NumOfElements * 2] = (ushort)uVar6;
      local_404[_NumOfElements * 2 + 1] = uVar2 + 2;
      uVar6 = uVar6 + 2 + (uint)uVar2;
    } while (uVar6 < uVar1);
  }
  _qsort(local_404 + 2,_NumOfElements,4,FUN_00610ac0);
  iVar7 = FUN_00633440(0x24,1);
  uVar6 = 0;
  if (iVar7 == 0) {
    local_40c[0] = 0;
  }
  else {
    local_40c[0] = FUN_00611190(param_1 + 8);
  }
  iVar7 = FUN_00633440(0x24,1);
  if (iVar7 == 0) {
    local_40c[1] = 0;
  }
  else {
    local_40c[1] = FUN_00611190(param_1 + 8);
  }
  if (_NumOfElements != 0) {
    do {
      iVar7 = local_40c[*(uint *)(local_40c[1] + 0x10) < *(uint *)(local_40c[0] + 0x10)];
      FUN_004ef660(*(int *)(iVar7 + 0xc) + *(int *)(iVar7 + 0x10),
                   (uint)local_404[uVar6 * 2 + 2] + *(int *)(param_1 + 0xc),local_404[uVar6 * 2 + 3]
                  );
      *(int *)(iVar7 + 0x10) = *(int *)(iVar7 + 0x10) + (uint)local_404[uVar6 * 2 + 3];
      uVar6 = uVar6 + 1;
    } while (uVar6 < _NumOfElements);
  }
  iVar7 = local_40c[0];
  iVar5 = FUN_00611290(local_40c[0]);
  iVar3 = local_40c[1];
  iVar8 = FUN_00611290(local_40c[1]);
  if (iVar7 != 0) {
    FUN_006334d0(*(undefined4 *)(iVar7 + 0xc),3000);
    FUN_006334d0(iVar7,0x24);
  }
  if (iVar3 != 0) {
    FUN_006334d0(*(undefined4 *)(iVar3 + 0xc),3000);
    FUN_006334d0(iVar3,0x24);
  }
  return iVar5 + iVar8;
}

