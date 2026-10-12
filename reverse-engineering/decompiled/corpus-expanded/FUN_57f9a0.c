/* Ghidra pseudocode, not original source.
 * ev_148a09dc694c3f4e6090ec8593a8f5c40e6398f75b0d17d245a3886ccb65c6ec
 * Entry: 0x57f9a0; label: FUN_0057f9a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_0057f9a0(undefined4 param_1)

{
  short sVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int unaff_ESI;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_005b37d0(&local_c,param_1);
  iVar5 = -1;
  if ((*(int *)(unaff_ESI + 4) != 0) &&
     (sVar1 = *(short *)(*(int *)(unaff_ESI + 4) + 0x1070), sVar1 != -1)) {
    iVar5 = (int)sVar1;
    FUN_0067c8e0(iVar5,0);
  }
  iVar4 = FUN_0067b430(param_1);
  if (iVar4 == 0) {
    *(undefined2 *)(unaff_ESI + 0xfa) = 0xffff;
    *(undefined1 *)(unaff_ESI + 0x104) = 0xff;
  }
  else {
    uVar3 = FUN_0067fb40();
    *(undefined2 *)(unaff_ESI + 0xfa) = uVar3;
    uVar2 = FUN_0067b210();
    *(undefined1 *)(unaff_ESI + 0x104) = uVar2;
    FUN_005b37d0(unaff_ESI + 300,param_1);
    *(undefined4 *)(unaff_ESI + 0x120) = DAT_0292fdb8;
    *(undefined4 *)(unaff_ESI + 0x124) = DAT_0292fdbc;
    *(undefined4 *)(unaff_ESI + 0x128) = DAT_0292fdc0;
  }
  if (iVar5 != -1) {
    FUN_0067c8e0(iVar5,1);
  }
  *(undefined4 *)(unaff_ESI + 0xb8) = local_c;
  *(undefined4 *)(unaff_ESI + 0xbc) = local_8;
  *(undefined4 *)(unaff_ESI + 0xc0) = local_4;
  DAT_02962b28 = 0;
  return iVar4 != 0;
}

