/* Ghidra pseudocode, not original source.
 * ev_f8ea80cbfae9cb61d37d4e579d4a737819a41489e1a74b58bc2061b157f40247
 * Entry: 0x6525a0; label: FUN_006525a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006525a0(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (((DAT_02962034 == 0) && (DAT_02962038 == 0)) && (_DAT_00810358 = param_1, DAT_00810490 == 4))
  {
    uVar1 = FUN_006e6b90();
    FUN_00698460((int)DAT_00810494,uVar1);
    return;
  }
  return;
}

