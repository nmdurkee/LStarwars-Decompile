/* Ghidra analysis pseudocode, not original source.
 * ev_8c0b129907146dba16e0c839f08bc31abcfde84bb6f318465034d474a072817c
 * Entry: 0x40ef00; label: FUN_0040ef00
 */

undefined4
FUN_0040ef00(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  
  puVar2 = (undefined4 *)FUN_0040ee70();
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  fVar1 = (float)in_ECX[0xc] - DAT_00973718;
  if (((float)in_ECX[0xe] - DAT_00973720) * ((float)in_ECX[0xe] - DAT_00973720) +
      fVar1 * fVar1 + ((float)in_ECX[0xd] - DAT_0097371c) * ((float)in_ECX[0xd] - DAT_0097371c) <
      40000.0) {
    switch(param_4) {
    case 0xfffffed4:
      pcVar5 = "Dog_CloneARC170Gun";
      break;
    case 0xfffffed5:
      pcVar5 = "Dog_TriFighterGuns";
      break;
    case 0xfffffed6:
    case 0xfffffed7:
      pcVar5 = "Dog_DroidFighterBlast";
      break;
    default:
      goto switchD_0040ef64_default;
    }
    FUN_00681f40(pcVar5,in_ECX + 0xc);
  }
switchD_0040ef64_default:
  puVar2[0x14] = param_2;
  puVar4 = puVar2;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *in_ECX;
    in_ECX = in_ECX + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_005b4dd0(puVar2,0x4000);
  puVar2[0x10] = *param_1;
  puVar2[0x11] = param_1[1];
  puVar2[0x12] = param_1[2];
  puVar2[0x13] = param_1[3];
  puVar2[0x16] = param_3;
  return 1;
}

