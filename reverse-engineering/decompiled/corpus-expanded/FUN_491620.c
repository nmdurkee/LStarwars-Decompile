/* Ghidra pseudocode, not original source.
 * ev_96df89c4daae28ff35d834560256e783041bc073304993e474c02e03eab098bd
 * Entry: 0x491620; label: FUN_00491620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00491620(void)

{
  int iVar1;
  short *psVar2;
  int in_ECX;
  
  iVar1 = 0;
  if (0 < DAT_0093b278) {
    do {
      *(undefined2 *)(in_ECX + iVar1 * 2) =
           *(undefined2 *)(*(int *)(DAT_029130e4 + 0x1c) + iVar1 * 2);
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_0093b278);
  }
  iVar1 = 0;
  if (0 < DAT_0093d500) {
    psVar2 = (short *)(DAT_0093d504 + 0x1064);
    do {
      if ((*(byte *)(psVar2 + -0x734) & 1) != 0) {
        *(undefined2 *)(in_ECX + *psVar2 * 2) = 0xffff;
      }
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 0x86c;
    } while (iVar1 < DAT_0093d500);
  }
  if (DAT_007f18fc != -1) {
    *(undefined2 *)(in_ECX + DAT_007f18fc * 2) = 0xffff;
  }
  if (DAT_007f1910 != -1) {
    *(undefined2 *)(in_ECX + DAT_007f1910 * 2) = 0xffff;
  }
  if (DAT_007f1958 != -1) {
    *(undefined2 *)(in_ECX + DAT_007f1958 * 2) = 0xffff;
  }
  if (DAT_007f18c4 != -1) {
    *(undefined2 *)(in_ECX + DAT_007f18c4 * 2) = 0xffff;
  }
  if (DAT_007f18e4 != -1) {
    *(undefined2 *)(in_ECX + DAT_007f18e4 * 2) = 0xffff;
  }
  if (DAT_007f18e8 != -1) {
    *(undefined2 *)(in_ECX + DAT_007f18e8 * 2) = 0xffff;
  }
  if (DAT_007f1a74 != -1) {
    *(undefined2 *)(in_ECX + DAT_007f1a74 * 2) = 0xffff;
  }
  if (DAT_007f1900 != -1) {
    *(undefined2 *)(in_ECX + DAT_007f1900 * 2) = 0xffff;
  }
  if (DAT_007f19dc != -1) {
    *(undefined2 *)(in_ECX + DAT_007f19dc * 2) = 0xffff;
  }
  if (DAT_007f17c4 != -1) {
    *(undefined2 *)(in_ECX + DAT_007f17c4 * 2) = 0xffff;
  }
  return;
}

