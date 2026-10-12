/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58a270; label: FUN_0058a270
 */

void FUN_0058a270(void)

{
  float fVar1;
  float fVar2;
  char cVar3;
  undefined4 uVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined *puVar9;
  float10 fVar10;
  int local_1c;
  float *local_18;
  int local_14;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  if ((((DAT_00804934 != 0) && (DAT_008264bc == 1)) && (DAT_008264c4 != '\0')) &&
     (local_14 = 0, iVar7 = DAT_0093d504, puVar9 = PTR_PTR_007fb0e4, 0 < DAT_0093d500)) {
    do {
      if ((((((*(uint *)(iVar7 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar7 + 0x1fc) & 0x1000) != 0)) &&
           ((*(char *)(iVar7 + 0x28b) == '\0' &&
            (((*(byte *)(iVar7 + 0xe20) & 0x20) == 0 ||
             ((*(uint *)(puVar9 + *(char *)(iVar7 + 0x7b5) * 0x10 + 8) & 0x40000) != 0)))))) &&
          ((*(uint *)(*(int *)(iVar7 + 0x54) + 4) & 0x10000) == 0)) &&
         ((((0.0 < *(float *)(iVar7 + 0x1020) && (*(char *)(iVar7 + 0x288) != '\0')) &&
           (bVar5 = 0, *(short *)(iVar7 + 0x105a) != 0)) &&
          (((*(uint *)(iVar7 + 0xef0) & 0x4000000) == 0 &&
           ((*(uint *)(puVar9 + *(char *)(iVar7 + 0x7b5) * 0x10 + 8) & 0x20000) == 0)))))) {
        cVar3 = *(char *)(*(int *)(*(int *)(iVar7 + 0x54) + 0x24) + 0xf6);
        if (cVar3 == -1) {
          cVar3 = *(char *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xa1);
        }
        if ((cVar3 != '\0') && (fVar1 = *(float *)(iVar7 + 0x1024), 0.0 < fVar1)) {
          fVar2 = *(float *)(iVar7 + 0xa8);
          fVar10 = (float10)FUN_00427ad0(iVar7);
          local_18 = (float *)(iVar7 + 0x838);
          puVar8 = (undefined4 *)(iVar7 + 0x6c4);
          local_1c = 0;
          iVar6 = 0x14;
          do {
            puVar9 = PTR_PTR_007fb0e4;
            if (4 < local_1c) break;
            if ((((uint)*(ushort *)(iVar7 + 0x105a) & 1 << (bVar5 & 0x1f)) != 0) &&
               (*(int *)(*(int *)(iVar7 + 0x50) + iVar6) != 0)) {
              if (((float)puVar8[1] != 2e+06) &&
                 ((0.0 < (float)puVar8[4] && ((float)puVar8[1] <= *local_18 + 0.025)))) {
                local_c = *puVar8;
                local_8 = (float)puVar8[1] + 0.005;
                local_4 = puVar8[2];
                uVar4 = FUN_006e6b90(*(undefined2 *)(puVar8 + 3),0,
                                     *(undefined2 *)((int)puVar8 + 0xe));
                FUN_005fee80(&local_c,(float)(fVar10 * (float10)(fVar1 * fVar2)),uVar4);
              }
              local_1c = local_1c + 1;
              puVar8 = puVar8 + 5;
            }
            local_18 = local_18 + 0x10;
            iVar6 = iVar6 + 4;
            bVar5 = bVar5 + 1;
            puVar9 = PTR_PTR_007fb0e4;
          } while (iVar6 < 0x54);
        }
      }
      local_14 = local_14 + 1;
      iVar7 = iVar7 + 0x10d8;
    } while (local_14 < DAT_0093d500);
  }
  return;
}

