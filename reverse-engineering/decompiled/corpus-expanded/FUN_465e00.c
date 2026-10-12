/* Ghidra pseudocode, not original source.
 * ev_8835491dd236cf2d19dd2fa5a5f724a0610b648b7dd0bb4146e1223777a8cf17
 * Entry: 0x465e00; label: FUN_00465e00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00465e00(undefined4 param_1,int *param_2)

{
  undefined1 uVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = FUN_006218c0();
  sVar2 = FUN_00621860();
  *(short *)(param_2 + 1) = sVar2;
  if (sVar2 == 0) {
    return 1;
  }
  iVar4 = *param_2;
  iVar5 = 0;
  if (sVar2 == 0) {
    return 1;
  }
  do {
    FUN_006216f0(iVar4,0x10);
    FUN_00621900(iVar4 + 0x10);
    uVar3 = FUN_006217e0();
    *(ushort *)(iVar4 + 0x2a) = *(ushort *)(iVar4 + 0x2a) | 3;
    *(undefined4 *)(iVar4 + 0x20) = uVar3;
    FUN_005aef10(*(undefined4 *)(iVar4 + 0x1c),param_1,0,uVar1,"BombGenerator",iVar4);
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 0x2c;
  } while (iVar5 < (int)(uint)*(ushort *)(param_2 + 1));
  return 1;
}

