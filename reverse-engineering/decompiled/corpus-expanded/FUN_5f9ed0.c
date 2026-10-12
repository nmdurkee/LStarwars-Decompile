/* Ghidra pseudocode, not original source.
 * ev_742d340bc2a041ef5ff6078bdc4a89a7f4acdb81012c0f9f5c92fd03ca8daa18
 * Entry: 0x5f9ed0; label: FUN_005f9ed0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f9ed0(undefined4 *param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4,
                 undefined1 param_5,undefined4 param_6,undefined1 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  uVar1 = DAT_02854bf4;
  if (DAT_00973fe8 < 0x118) {
    iVar2 = DAT_00973fe8 * 0x68;
    (&DAT_0096670c)[DAT_00973fe8 * 0x1a] = _DAT_00973fe0;
    (&DAT_00966710)[DAT_00973fe8 * 0x1a] = _DAT_00973fe4;
    (&DAT_009666fc)[DAT_00973fe8 * 0x1a] = uVar1;
    (&DAT_00966700)[DAT_00973fe8 * 0x1a] = DAT_02854bf8;
    (&DAT_00966704)[DAT_00973fe8 * 0x1a] = DAT_02854bfc;
    *(int *)(&DAT_00966708 + iVar2) = (int)DAT_02854c00._3_1_;
    puVar4 = (undefined4 *)(&DAT_009666b0 + iVar2);
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *param_1;
      param_1 = param_1 + 1;
      puVar4 = puVar4 + 1;
    }
    *(undefined4 *)(&DAT_009666f0 + iVar2) = param_2;
    (&DAT_00966714)[iVar2] = param_3;
    (&DAT_009666f4)[DAT_00973fe8 * 0x1a] = param_4;
    (&DAT_00966715)[iVar2] = param_5;
    *(undefined4 *)(&DAT_009666f8 + iVar2) = param_6;
    (&DAT_00966716)[iVar2] = param_7;
    DAT_00973fe8 = DAT_00973fe8 + 1;
    (&DAT_00966717)[iVar2] = (char)DAT_00973fdc;
    DAT_00973fdc = DAT_00973fdc + 1;
  }
  return;
}

