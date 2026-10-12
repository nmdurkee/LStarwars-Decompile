/* Ghidra analysis pseudocode, not original source.
 * ev_45ac563217612fbe2426642b00b9c96cf69ca1c78f087433beffcbe1e9bd0306
 * Entry: 0x528210; label: FUN_00528210
 */

void FUN_00528210(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  float10 fVar6;
  
  iVar5 = 0;
  if (0xc < DAT_0080171c) {
    for (iVar2 = FUN_004f1440(DAT_009238e4 + 0x43814); iVar2 != 0;
        iVar2 = FUN_004f1460(DAT_009238e4 + 0x43814,iVar2)) {
      iVar5 = iVar5 + 1;
    }
    FUN_00621520(iVar5);
    if (iVar5 != 0) {
      for (iVar5 = FUN_004f1440(DAT_009238e4 + 0x43814); iVar5 != 0;
          iVar5 = FUN_004f1460(DAT_009238e4 + 0x43814,iVar5)) {
        if (*(char *)(iVar5 + 0x49) == '\x02') {
          fVar6 = (float10)FUN_005c0240(*(float *)(iVar5 + 0x40) * *(float *)(iVar5 + 0x40) +
                                        *(float *)(iVar5 + 0x44) * *(float *)(iVar5 + 0x44));
LAB_005282db:
          *(float *)(iVar5 + 0x14) = (float)fVar6;
        }
        else if (*(char *)(iVar5 + 0x49) == '\x01') {
          if (*(float *)(iVar5 + 0x40) <= *(float *)(iVar5 + 0x44)) {
            fVar6 = (float10)*(float *)(iVar5 + 0x44);
          }
          else {
            fVar6 = (float10)*(float *)(iVar5 + 0x40);
          }
          goto LAB_005282db;
        }
        FUN_006214d0(*(undefined4 *)(iVar5 + 8));
        FUN_006214d0(*(undefined4 *)(iVar5 + 0xc));
        FUN_006214d0(*(undefined4 *)(iVar5 + 0x10));
        FUN_006214d0(*(undefined4 *)(iVar5 + 0x14));
        FUN_006214d0(*(float *)(iVar5 + 0x18) + *(float *)(iVar5 + 0xc));
        FUN_006214d0(*(float *)(iVar5 + 0x1c) + *(float *)(iVar5 + 0xc));
        if (DAT_0080171c < 0xf) {
          FUN_00621600(0);
          FUN_00621600(0);
          FUN_00621600(0);
        }
        else {
          FUN_00621520(*(undefined4 *)(iVar5 + 0x3c));
          FUN_006214d0(*(undefined4 *)(iVar5 + 0x40));
          FUN_006214d0(*(undefined4 *)(iVar5 + 0x44));
          FUN_00621600(*(undefined1 *)(iVar5 + 0x49));
          FUN_00621600(0);
          FUN_00621600(0);
        }
        FUN_00621600(*(undefined1 *)(iVar5 + 0x48));
        iVar2 = FUN_005cfac0(iVar5 + 0x20);
        if ((iVar2 == 0) || (pcVar3 = (char *)FUN_005cfa50(iVar5 + 0x20), pcVar3 == (char *)0x0)) {
          FUN_00621600(0);
        }
        else {
          pcVar4 = pcVar3;
          do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          FUN_00621600(pcVar4 + (1 - (int)(pcVar3 + 1)));
          FUN_00621440(pcVar3,pcVar4 + (1 - (int)(pcVar3 + 1)));
          FUN_006214d0(*(undefined4 *)(iVar5 + 0x2c));
          FUN_006214d0(*(undefined4 *)(iVar5 + 0x30));
          FUN_006214d0(*(undefined4 *)(iVar5 + 0x34));
          if (0xe < DAT_0080171c) {
            FUN_00621520(*(undefined4 *)(iVar5 + 0x38));
          }
        }
      }
    }
  }
  return;
}

