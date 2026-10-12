/* Ghidra pseudocode, not original source.
 * ev_b07f36f396508f1f1c6b60e4fa7f99c8658995938fec5aefc7408e7826e0de77
 * Entry: 0x65d880; label: FUN_0065d880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0065d880(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  iVar2 = DAT_02962978;
  iVar4 = 0;
  if (DAT_02962974 == 0x40) {
    return -1;
  }
  if (DAT_02947db4 != -1) {
    pcVar3 = &DAT_02947db4;
    do {
      pcVar3 = pcVar3 + 0x44;
      iVar4 = iVar4 + 1;
    } while (*pcVar3 != -1);
  }
  DAT_02962974 = DAT_02962974 + 1;
  iVar1 = iVar4 * 0x44;
  (&DAT_02947dc0)[iVar4 * 0x11] = 0x3e3851ec;
  (&DAT_02947db4)[iVar1] = (char)iVar2;
  (&DAT_02947dc4)[iVar4 * 0x11] = 0x3dcccccd;
  (&DAT_02947dd8)[iVar1] = 0x50;
  (&DAT_02947dd9)[iVar1] = 0x50;
  (&DAT_02947dc8)[iVar4 * 0x11] = 0xbc23d70a;
  (&DAT_02947dda)[iVar1] = 0x30;
  (&DAT_02947ddb)[iVar1] = 0x80;
  (&DAT_02947dcc)[iVar4 * 0x11] = 0x40800000;
  (&DAT_029211c8)[iVar2] = 1;
  (&DAT_02947dd0)[iVar4 * 0x11] = 0x3f000000;
  (&DAT_02947dd4)[iVar4 * 0x11] = 0x3f000000;
  *(undefined4 *)(&DAT_0292fc3c + iVar2 * 4) = DAT_02962114;
  FUN_0065d7d0(iVar4,param_1);
  return iVar4;
}

