/* Ghidra pseudocode, not original source.
 * ev_82e843d85b8a15ad0c2712a3dca0d893aca885ca51044f6184084df2488405d8
 * Entry: 0x474f50; label: FUN_00474f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00474f50(void)

{
  short sVar1;
  short *in_EAX;
  undefined4 uVar2;
  int unaff_EDI;
  
  sVar1 = *in_EAX;
  while (sVar1 != -1) {
    sVar1 = *in_EAX;
    if ((sVar1 < 0) || (DAT_00956294 <= sVar1)) {
      in_EAX[10] = 0;
      in_EAX[0xb] = 0;
    }
    else {
      *(int *)(in_EAX + 10) = DAT_00956290 + sVar1 * 0x1c;
    }
    uVar2 = FUN_0055a020(*(undefined4 *)(unaff_EDI + 0x2ac8),0xffffffff,*(undefined4 *)(in_EAX + 2))
    ;
    *(undefined4 *)(in_EAX + 0xc) = uVar2;
    FUN_005cf5b0(*(undefined4 *)(unaff_EDI + 0x13c),in_EAX + 0xe,*(undefined4 *)(in_EAX + 4),1);
    in_EAX = in_EAX + 0x14;
    sVar1 = *in_EAX;
  }
  return;
}

