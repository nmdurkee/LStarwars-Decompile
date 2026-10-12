/* Ghidra analysis pseudocode, not original source.
 * ev_988aedce7a102035a37775149c4794654cf73d0aa98e786da352e425eaa98523
 * Entry: 0x43a910; label: FUN_0043a910
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043a910(int param_1)

{
  bool bVar1;
  undefined *puVar2;
  uint *puVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  undefined8 uVar11;
  int local_20c;
  int local_208;
  int local_204;
  int local_200 [64];
  int local_100 [64];
  
  puVar2 = PTR_DAT_00802c54;
  iVar10 = 0;
  iVar6 = 0;
  local_208 = 0;
  local_20c = 0;
  piVar5 = local_200;
  piVar9 = local_100;
  iVar8 = DAT_0093d504;
  iVar7 = DAT_0093d500;
  if (0 < DAT_0093d500) {
    do {
      if ((((*(uint *)(iVar8 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar8 + 0x1fc) & 0x1000) != 0)) &&
         (*(char *)(iVar8 + 0x28b) == '\0')) {
        if ((*(uint *)(iVar8 + 0x1f8) & 1) == 0) {
          if ((*(uint *)(iVar8 + 0x1f8) & 4) == 0) {
            iVar10 = iVar10 + 1;
            *piVar5 = iVar8;
            piVar5 = piVar5 + 1;
          }
        }
        else {
          iVar6 = iVar6 + 1;
          *piVar9 = iVar8;
          piVar9 = piVar9 + 1;
        }
      }
      iVar7 = iVar7 + -1;
      iVar8 = iVar8 + 0x10d8;
      local_20c = iVar6;
      local_208 = iVar10;
    } while (iVar7 != 0);
  }
  if ((param_1 != 0) && (local_204 = 0, 0 < local_208)) {
    do {
      iVar8 = 0;
      if (0 < local_20c) {
        uVar11 = __allshl();
        uVar4 = (uint)((ulonglong)uVar11 >> 0x20);
        do {
          iVar7 = local_100[iVar8];
          if (((*(uint *)(iVar7 + 0x2a8) & (uint)uVar11) != 0 ||
               (*(uint *)(iVar7 + 0x2ac) & uVar4) != 0) &&
             ((*(uint *)(*(int *)(puVar2 + 0x298c) + 8 + (uint)*(byte *)(iVar7 + 0x28d) * 8) &
              (uint)uVar11) != 0 ||
              (*(uint *)(*(int *)(puVar2 + 0x298c) + 0xc + (uint)*(byte *)(iVar7 + 0x28d) * 8) &
              uVar4) != 0)) {
            return;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < local_20c);
      }
      local_204 = local_204 + 1;
    } while (local_204 < local_208);
  }
  iVar8 = 0;
  if (0 < local_208) {
    do {
      iVar7 = 0;
      if (0 < local_20c) {
        iVar6 = local_200[iVar8];
        do {
          iVar10 = local_100[iVar7];
          uVar11 = __allshl();
          puVar3 = (uint *)(iVar10 + 0x2a8);
          *puVar3 = *puVar3 & ~(uint)uVar11;
          puVar3 = (uint *)(iVar10 + 0x2ac);
          *puVar3 = *puVar3 & ~(uint)((ulonglong)uVar11 >> 0x20);
          uVar11 = __allshl();
          puVar3 = (uint *)(iVar6 + 0x2a8);
          *puVar3 = *puVar3 & ~(uint)uVar11;
          puVar3 = (uint *)(iVar6 + 0x2ac);
          *puVar3 = *puVar3 & ~(uint)((ulonglong)uVar11 >> 0x20);
          iVar7 = iVar7 + 1;
        } while (iVar7 < local_20c);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < local_208);
  }
  iVar8 = 0;
  if (0 < DAT_0093d500) {
    puVar3 = (uint *)(DAT_0093d504 + 0x1fc);
    do {
      if ((((*puVar3 & 1) != 0) && ((*puVar3 & 0x1000) != 0)) &&
         (*(char *)((int)puVar3 + 0x8f) == '\0')) {
        puVar3[0xad] = puVar3[0xad] & 0xffffa7ff;
        puVar3[0x6d] = 0x4e6e6b28;
        puVar3[0x69] = 0x4e6e6b28;
        puVar3[0x6c] = 0;
        puVar3[0x6b] = 0x4e6e6b28;
        puVar3[0x68] = 0;
        puVar3[0x6f] = 0x4e6e6b28;
        puVar3[0x6a] = 0;
        puVar3[0x6e] = 0;
        puVar3[0x2b] = 0;
        puVar3[0x2c] = 0;
        puVar3[0x32d] = 0;
        puVar3[0x32e] = 0;
        puVar3[0x331] = 0;
      }
      iVar8 = iVar8 + 1;
      puVar3 = puVar3 + 0x436;
    } while (iVar8 < DAT_0093d500);
  }
  _DAT_00876cdc = 0;
  DAT_00876cc8 = 0;
  DAT_00876cd8 = 0;
  if (((DAT_007f39e4 != 0) &&
      ((DAT_0087af98 == 0 || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af98)))) &&
     (DAT_00876ccc == 0)) {
    bVar1 = true;
    piVar5 = &DAT_0093d7f4;
    do {
      iVar8 = piVar5[-1];
      if (((iVar8 != 0) && ((*(uint *)(iVar8 + 0x1fc) & 1) != 0)) &&
         (((*(uint *)(iVar8 + 0x1fc) & 0x1000) != 0 &&
          ((*(char *)(iVar8 + 0x28b) == '\0' && ((*(byte *)(iVar8 + 0xef3) & 1) == 0)))))) {
        if ((*(char *)(iVar8 + 0x1082) == '\x05') ||
           ((((DAT_0093b2a4 != 0 || (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b94)) &&
             ((*(uint *)(*(int *)(iVar8 + 0x54) + 4) & 0x204) != 0)) &&
            (*(int *)(iVar8 + 0xcd0) == 0)))) {
          DAT_00876cc8 = 1;
        }
        if ((*(uint *)(*(int *)(iVar8 + 0x54) + 4) & 0x80000) == 0) {
          bVar1 = false;
        }
      }
      iVar8 = *piVar5;
      if (((iVar8 != 0) && ((*(uint *)(iVar8 + 0x1fc) & 1) != 0)) &&
         (((*(uint *)(iVar8 + 0x1fc) & 0x1000) != 0 &&
          ((*(char *)(iVar8 + 0x28b) == '\0' && ((*(byte *)(iVar8 + 0xef3) & 1) == 0)))))) {
        if ((*(char *)(iVar8 + 0x1082) == '\x05') ||
           ((((DAT_0093b2a4 != 0 || (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b94)) &&
             ((*(uint *)(*(int *)(iVar8 + 0x54) + 4) & 0x204) != 0)) &&
            (*(int *)(iVar8 + 0xcd0) == 0)))) {
          DAT_00876cc8 = 1;
        }
        if ((*(uint *)(*(int *)(iVar8 + 0x54) + 4) & 0x80000) == 0) {
          bVar1 = false;
        }
      }
      iVar8 = piVar5[1];
      if (((iVar8 != 0) && ((*(uint *)(iVar8 + 0x1fc) & 1) != 0)) &&
         (((*(uint *)(iVar8 + 0x1fc) & 0x1000) != 0 &&
          ((*(char *)(iVar8 + 0x28b) == '\0' && ((*(byte *)(iVar8 + 0xef3) & 1) == 0)))))) {
        if ((*(char *)(iVar8 + 0x1082) == '\x05') ||
           ((((DAT_0093b2a4 != 0 || (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b94)) &&
             ((*(uint *)(*(int *)(iVar8 + 0x54) + 4) & 0x204) != 0)) &&
            (*(int *)(iVar8 + 0xcd0) == 0)))) {
          DAT_00876cc8 = 1;
        }
        if ((*(uint *)(*(int *)(iVar8 + 0x54) + 4) & 0x80000) == 0) {
          bVar1 = false;
        }
      }
      iVar8 = piVar5[2];
      if (((iVar8 != 0) && ((*(uint *)(iVar8 + 0x1fc) & 1) != 0)) &&
         (((*(uint *)(iVar8 + 0x1fc) & 0x1000) != 0 &&
          ((*(char *)(iVar8 + 0x28b) == '\0' && ((*(byte *)(iVar8 + 0xef3) & 1) == 0)))))) {
        if ((*(char *)(iVar8 + 0x1082) == '\x05') ||
           ((((DAT_0093b2a4 != 0 || (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b94)) &&
             ((*(uint *)(*(int *)(iVar8 + 0x54) + 4) & 0x204) != 0)) &&
            (*(int *)(iVar8 + 0xcd0) == 0)))) {
          DAT_00876cc8 = 1;
        }
        if ((*(uint *)(*(int *)(iVar8 + 0x54) + 4) & 0x80000) == 0) {
          bVar1 = false;
        }
      }
      piVar5 = piVar5 + 4;
    } while ((int)piVar5 < 0x93d814);
    if (bVar1) {
      DAT_00876cc8 = 1;
    }
  }
  return;
}

