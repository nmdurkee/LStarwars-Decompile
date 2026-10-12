/* Ghidra pseudocode, not original source.
 * ev_ba19024e936acaebc8caa887b02629c3d2df1b51d473842281df89ce325ba5c8
 * Entry: 0x548f20; label: FUN_00548f20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00548f20(undefined *param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  PTR_DAT_008020bc = param_1;
  iVar3 = 0x158;
  iVar2 = 8;
  do {
    uVar1 = FUN_00650dc0(*(undefined4 *)(param_1 + iVar2));
    param_1 = PTR_DAT_008020bc;
    *(undefined2 *)(PTR_DAT_008020bc + iVar3) = uVar1;
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + 2;
  } while (iVar2 < 0x158);
  FUN_005097a0((int)*(short *)(param_1 + 0x1b6),(int)*(short *)(param_1 + 0x1b8),
               (int)*(short *)(param_1 + 0x1ba),(int)*(short *)(param_1 + 0x1bc));
  return;
}

