/* Ghidra pseudocode, not original source.
 * ev_9d34c938d292037f498e462893e532f4f6f058923093d2cacbd29fd836aaae04
 * Entry: 0x506490; label: FUN_00506490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00506490(void)

{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 extraout_EDX;
  int local_114;
  int local_110;
  undefined1 local_10c [8];
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_114;
  if (((DAT_00921378 != 0) && (DAT_009213c8 == 0)) && (*(int *)(DAT_00921378 + 0x58) != 0)) {
    FUN_004f1f10(local_104,*(undefined4 *)(*(int *)(DAT_00921378 + 0x58) + 0x2c));
    pcVar4 = (char *)FUN_004f20a0(local_104,&DAT_0075ebb0);
    FUN_004f1f10(local_10c,pcVar4);
    uVar3 = (*(byte *)(DAT_00921378 + 0xdf) + 1) / 10;
    bVar2 = *(byte *)(DAT_00921378 + 0xdf);
    if (uVar3 != 0) {
      *pcVar4 = (char)uVar3 + '0';
      pcVar4 = pcVar4 + 1;
    }
    *pcVar4 = (char)((ulonglong)(bVar2 + 1) % 10) + '0';
    FUN_004f1f10(pcVar4 + 1,local_10c);
    local_114 = *(int *)(DAT_00921378 + 0xec);
    *(undefined4 *)(DAT_00921378 + 0xec) = 0;
    if (local_114 != 0) {
      *(uint *)(DAT_00921378 + 0x8c) = *(uint *)(DAT_00921378 + 0x8c) | 0x80;
      local_110 = *(int *)(*(int *)(DAT_00921378 + 0x58) + 0x3c) + local_114;
      FUN_004fff10(local_104,local_114);
      uVar5 = FUN_004fff20(extraout_EDX);
      FUN_00505820(uVar5,&local_114,&local_110,1);
      FUN_004fff20(local_104);
      *(uint *)(DAT_00921378 + 0x88) = *(uint *)(DAT_00921378 + 0x88) | 0x8000000;
      if ((*(char *)(DAT_00921378 + 0xdf) == '\0') &&
         ((*(byte *)(*(int *)(DAT_00921378 + 0x58) + 0x38) & 8) != 0)) {
        FUN_005009d0(DAT_00921378,1);
        if (DAT_00800890 < 2) {
          FUN_00500830(*(undefined4 *)(DAT_00921378 + 0x58),
                       *(undefined4 *)(*(int *)(DAT_00921378 + 0x58) + 0x34));
        }
        else {
          *(uint *)(DAT_00921378 + 0x88) = *(uint *)(DAT_00921378 + 0x88) | 0x10000000;
          FUN_00500600(DAT_00921378);
        }
        puVar1 = (uint *)(*(int *)(DAT_00921378 + 0x58) + 0x38);
        *puVar1 = *puVar1 & 0xfffffff7;
        *(uint *)(DAT_00921378 + 0x88) = *(uint *)(DAT_00921378 + 0x88) & 0xf7ffffff;
        *(undefined1 *)(DAT_00921378 + 0xdf) = 1;
      }
      *(uint *)(DAT_00921378 + 0x8c) = *(uint *)(DAT_00921378 + 0x8c) & 0xffffff7f;
      DAT_00921378 = 0;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_114);
  return;
}

