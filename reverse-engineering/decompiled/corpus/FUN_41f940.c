/* Ghidra analysis pseudocode, not original source.
 * ev_fc46cff07f0ed537c3533760820ac45bd355561daa184f1b787f47d220e25ab8
 * Entry: 0x41f940; label: FUN_0041f940
 */

void FUN_0041f940(void)

{
  char cVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  undefined *puVar10;
  short *local_8;
  undefined *local_4;
  
  DAT_0093d7f0 = 0;
  DAT_0093d7f4 = 0;
  DAT_0093d7f8 = 0;
  DAT_0093d7fc = 0;
  DAT_0093d800 = 0;
  DAT_0093d804 = 0;
  DAT_0093d808 = 0;
  DAT_0093d80c = 0;
  if (DAT_00951b50 != 0) {
    DAT_0093d7f0 = 0;
    DAT_0093d7f4 = 0;
    DAT_0093d7f8 = 0;
    DAT_0093d7fc = 0;
    DAT_0093d800 = 0;
    DAT_0093d804 = 0;
    DAT_0093d808 = 0;
    DAT_0093d80c = 0;
    return;
  }
  DAT_0093d818 = 0;
  if ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 2) == 0) goto LAB_0041fd9f;
  if ((DAT_0093b2a4 == 0) &&
     (((DAT_0093d820 == 0 || (DAT_00951364 == 0)) ||
      (*(int *)(PTR_DAT_00802c54 + 300) != DAT_00951364)))) {
    if (DAT_0093d81c == 1) {
      local_8 = &DAT_0093d590;
      if (DAT_0093d590 != -1) {
        if (*(short *)(*(int *)(DAT_029130e4 + 0x1c) + DAT_0093d590 * 2) == -1) goto LAB_0041f9f1;
        if ((DAT_0093d592 != -1) &&
           (*(short *)(*(int *)(DAT_029130e4 + 0x1c) + DAT_0093d592 * 2) == -1)) {
          local_8 = &DAT_0095107c;
        }
      }
    }
    else {
LAB_0041f9f1:
      local_8 = &DAT_0095107c;
    }
  }
  else {
    local_8 = &DAT_0093d590;
  }
  if (((((DAT_0087b2d4 == 0) && (DAT_0093d81c != 0)) &&
       ((DAT_0093d516 == '\0' &&
        ((((DAT_0093d526 != '\0' && (DAT_0093b2a4 == 0)) &&
          ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 5) == 1)) &&
         ((sVar2 = *local_8, sVar2 != -1 && (sVar2 == DAT_00951090)))))))) &&
      (sVar3 = local_8[1], sVar3 != -1)) && ((sVar3 == DAT_00951094 && (sVar2 != sVar3)))) {
    *local_8 = sVar3;
    local_8[1] = sVar2;
  }
  sVar2 = *local_8;
  local_4 = (undefined *)0x0;
  while ((sVar2 != -1 && ((int)local_4 < 8))) {
    uVar8 = (uint)local_8[(int)local_4];
    if ((uVar8 < 0x154) &&
       ((*(short *)(*(int *)(DAT_029130e4 + 0x1c) + uVar8 * 2) != -1 &&
        (iVar4 = FUN_0055c9f0(), iVar4 != 0)))) {
      FUN_0041c7c0(iVar4,uVar8,1);
      FUN_00498a40(iVar4);
      FUN_004b6b80(iVar4);
      iVar6 = DAT_0093d818;
      (&DAT_0093d7f0)[DAT_0093d818] = iVar4;
      *(undefined **)(iVar4 + 0xca8) = &DAT_0093d630 + iVar6 * 0x38;
      *(char *)((&DAT_0093d7f0)[DAT_0093d818] + 0x280) = (char)DAT_0093d818;
      *(undefined **)((&DAT_0093d7f0)[DAT_0093d818] + 0xcc0) = &DAT_00854898 + DAT_0093d818 * 0xb4;
      uVar5 = FUN_004d22b0();
      *(undefined4 *)((&DAT_0093d7f0)[DAT_0093d818] + 0xcc4) = uVar5;
      DAT_0093d818 = DAT_0093d818 + 1;
      *(uint *)(iVar4 + 0x1044) = *(uint *)(iVar4 + 0x1044) | 1;
      *(undefined1 *)(iVar4 + 0x107e) = DAT_00802bd4;
      *(undefined1 *)(iVar4 + 0x1082) = 0;
      if (DAT_0093d81c == 0) {
        if (*(byte *)(iVar4 + 0x28d) == 0) {
          *(uint *)(iVar4 + 0x1fc) = *(uint *)(iVar4 + 0x1fc) | 0x80;
        }
        else {
          *(uint *)(iVar4 + 0x1fc) = *(uint *)(iVar4 + 0x1fc) & 0xffffff7f;
        }
        (&DAT_0093d518)[(uint)*(byte *)(iVar4 + 0x28d) * 0x10] = *(undefined1 *)(iVar4 + 0x107f);
LAB_0041fc90:
        *(undefined2 *)(iVar4 + 0x1062) = 0;
      }
      else {
        iVar9 = (int)*(char *)(iVar4 + 0x280);
        iVar6 = iVar9 * 0x10;
        *(uint *)(iVar4 + 0x1fc) =
             *(uint *)(iVar4 + 0x1fc) ^
             ((uint)(byte)(&DAT_0093d516)[iVar6] << 7 ^ *(uint *)(iVar4 + 0x1fc)) & 0x80;
        if (DAT_00803784 != DAT_0095121c) {
          *(uint *)(iVar4 + 0xe20) = *(uint *)(iVar4 + 0xe20) & 0xfffeffff;
          goto LAB_0041fc90;
        }
        if (DAT_0093d81c == 1) {
          *(uint *)(iVar4 + 0xe20) =
               *(uint *)(iVar4 + 0xe20) ^
               ((uint)(byte)(&DAT_0093d517)[iVar6] << 0x10 ^ *(uint *)(iVar4 + 0xe20)) & 0x10000;
          cVar1 = (&DAT_0093d518)[iVar6];
          *(char *)(iVar4 + 0x107f) = cVar1;
          if ((int)(uint)*(byte *)(iVar4 + 0x107e) < (int)cVar1) {
            *(byte *)(iVar4 + 0x107f) = *(byte *)(iVar4 + 0x107e);
          }
          *(undefined1 *)(iVar4 + 0x1082) = (&DAT_0093d51a)[iVar6];
          *(undefined2 *)(iVar4 + 0x1062) = (&DAT_0093d514)[iVar9 * 8];
          *(undefined4 *)(iVar4 + 0xdec) = (&DAT_0093d51c)[iVar9 * 4];
          *(undefined4 *)(iVar4 + 0xcbc) = (&DAT_00855e84)[iVar9];
          if (*(undefined1 **)(iVar4 + 0xcc4) != (undefined1 *)0x0) {
            **(undefined1 **)(iVar4 + 0xcc4) = (&DAT_00881258)[iVar9];
          }
        }
      }
      iVar6 = *(short *)(iVar4 + 0x1064) * 0x4c;
      *(undefined4 *)(iVar4 + 0x230) =
           *(undefined4 *)(*(int *)(*(int *)(DAT_029130e4 + 0x20) + 0x24 + iVar6) + 100);
      *(undefined4 *)(iVar4 + 0x234) =
           *(undefined4 *)(*(int *)(*(int *)(DAT_029130e4 + 0x20) + 0x24 + iVar6) + 0x68);
      *(undefined4 *)(iVar4 + 0x238) =
           *(undefined4 *)(*(int *)(*(int *)(DAT_029130e4 + 0x20) + 0x24 + iVar6) + 0x6c);
      uVar5 = *(undefined4 *)(*(int *)(*(int *)(DAT_029130e4 + 0x20) + 0x24 + iVar6) + 0x70);
      *(uint *)(iVar4 + 0x4b0) = *(uint *)(iVar4 + 0x4b0) & 0xffffafff;
      *(uint *)(iVar4 + 0xeec) = *(uint *)(iVar4 + 0xeec) & 0xfffff7fe;
      *(undefined4 *)(iVar4 + 0x23c) = uVar5;
      *(uint *)(iVar4 + 0xef4) = *(uint *)(iVar4 + 0xef4) | 0x40;
      *(undefined4 *)(iVar4 + 0x3a8) = 0x4e6e6b28;
      *(undefined4 *)(iVar4 + 0x39c) = 0;
      *(undefined4 *)(iVar4 + 0x3b8) = 0x4e6e6b28;
      *(undefined4 *)(iVar4 + 0x3a4) = 0;
      *(undefined4 *)(iVar4 + 0x3ac) = 0;
      *(undefined4 *)(iVar4 + 0xec4) = 0;
      *(undefined4 *)(iVar4 + 0x3b4) = 0;
      *(undefined4 *)(iVar4 + 0x454) = 0;
      *(undefined4 *)(iVar4 + 0x2a8) = 0;
      *(undefined4 *)(iVar4 + 0xecc) = 0;
      *(undefined4 *)(iVar4 + 0x2ac) = 0;
      *(undefined4 *)(iVar4 + 0xeb0) = 0;
      *(undefined4 *)(iVar4 + 0xeb4) = 0;
      *(undefined4 *)(iVar4 + 0x10a4) = 0;
      *(undefined4 *)(iVar4 + 0x10a8) = 0;
      *(undefined4 *)(iVar4 + 0xec0) = 0;
      *(undefined4 *)(iVar4 + 0xeb8) = 0;
      *(undefined4 *)(iVar4 + 0xebc) = 0;
    }
    local_4 = (undefined *)((int)local_4 + 1);
    sVar2 = local_8[(int)local_4];
  }
LAB_0041fd9f:
  DAT_0093d81c = 0;
  local_4 = &DAT_0093b350;
  piVar7 = &DAT_0093d7f0;
  puVar10 = &DAT_00876e78;
  iVar4 = 0;
  do {
    if (*piVar7 != 0) {
      *(int *)(*piVar7 + 0x7fc) = (int)&DAT_00855f38 + iVar4;
      *(undefined2 *)(*(int *)(*piVar7 + 0x7fc) + 8) = DAT_00803bac;
      if (DAT_00803784 == DAT_0095121c) {
        **(undefined4 **)(*piVar7 + 0x7fc) = *(undefined4 *)((int)&DAT_0093d510 + iVar4);
      }
      else {
        **(undefined4 **)(*piVar7 + 0x7fc) = 0;
      }
      *(undefined **)(*piVar7 + 0x800) = puVar10;
      _memcpy(local_4,(void *)*piVar7,0x10d8);
    }
    local_4 = local_4 + 0x10d8;
    puVar10 = puVar10 + 0x630;
    iVar4 = iVar4 + 0x10;
    piVar7 = piVar7 + 1;
  } while ((int)puVar10 < 0x877ad8);
  if (DAT_0093d7f4 == 0) {
    iVar4 = -1;
  }
  else {
    iVar4 = (int)*(short *)(DAT_0093d7f4 + 0x1064);
  }
  if (DAT_0093d7f0 == 0) {
    FUN_0055e1b0(0,0xffffffff,iVar4);
    return;
  }
  FUN_0055e1b0(0,(int)*(short *)(DAT_0093d7f0 + 0x1064),iVar4);
  return;
}

