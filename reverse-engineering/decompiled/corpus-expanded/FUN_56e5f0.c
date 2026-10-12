/* Ghidra pseudocode, not original source.
 * ev_b786d52b0c6475300075d44c367bc307b08211d5064c161e2619fa192a4bae5f
 * Entry: 0x56e5f0; label: FUN_0056e5f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 *
FUN_0056e5f0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined2 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  bool bVar5;
  
  iVar3 = DAT_00950f58;
  iVar2 = DAT_00950f58 * 0x38;
  *(undefined4 *)(&DAT_00950da4 + iVar2) = *param_1;
  *(undefined4 *)(&DAT_00950da8 + iVar2) = param_1[1];
  uVar1 = param_1[2];
  *(undefined4 *)(&DAT_00950db0 + iVar2) = param_2;
  (&DAT_00950db4)[iVar3 * 0xe] = 0;
  *(undefined4 *)(&DAT_00950dac + iVar2) = uVar1;
  (&DAT_00950db8)[iVar3 * 0xe] = param_3;
  (&DAT_00950da0)[iVar3 * 0xe] = param_4;
  *(undefined4 *)(&DAT_00950d98 + iVar2) = 0;
  *(undefined4 *)(&DAT_00950d9c + iVar2) = 0;
  uVar4 = FUN_0054fa60();
  *(undefined2 *)(&DAT_00950dc2 + iVar2) = uVar4;
  *(undefined2 *)(&DAT_00950dc4 + iVar2) = param_5;
  *(undefined4 *)(&DAT_00950dbc + iVar2) = param_6;
  uVar4 = FUN_0058b720(param_4);
  *(undefined2 *)(&DAT_00950dc6 + iVar2) = uVar4;
  DAT_00950f58 = DAT_00950f58 + 1;
  bVar5 = DAT_00950f58 == 8;
  *(undefined2 *)(&DAT_00950dc8 + iVar2) = 0;
  (&DAT_00950dca)[iVar2] = 1;
  (&DAT_00950dcb)[iVar2] = 0xff;
  if (bVar5) {
    DAT_00950f58 = 0;
  }
  return (undefined4 *)(&DAT_00950d98 + iVar2);
}

