/* Ghidra analysis pseudocode, not original source.
 * ev_8be49e78861dfe08cca82ea9c09c813f64ee3632778122cedbbea2ab2ea39171
 * Entry: 0x606a40; label: FUN_00606a40
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00606a40(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 uVar5;
  undefined4 local_30;
  float local_2c;
  undefined1 local_20 [28];
  
  iVar1 = *(int *)(DAT_0080bbb4 + DAT_0080bbb0 * 0x28);
  piVar2 = *(int **)(DAT_0080bbbc + DAT_0080bbb8 * 0x28);
  if (*(char *)((int)piVar2 + 9) == '\0') {
    *(undefined1 *)((int)piVar2 + 9) = 1;
  }
  iVar3 = *piVar2;
  local_30 = 0;
  local_2c = *(float *)(*(int *)(in_ECX + 0x1c) + 0x88) * _DAT_0080ea00;
  FUN_005c5020(local_20);
  FUN_006e2320(in_ECX + 0x20,2,0);
  FUN_006e5340(0x16,1);
  FUN_006e5340(0xf,0);
  FUN_006e5340(0x1b,0);
  FUN_006e5340(7,0);
  FUN_006e5340(0xa8,0xf);
  FUN_005f8bf0(iVar1);
  if ((iVar1 == DAT_028492f4) && (DAT_02976c7c != 0)) {
    *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xfc13ffff | 0x120000;
    FUN_005fa0a0();
    FUN_006059c0();
    FUN_006e23e0();
  }
  FUN_005fa0a0();
  FUN_006e5750(*(undefined4 *)(in_ECX + 0x3c),&local_30,2);
  DAT_02854c2c[8] = DAT_02854c2c[8] & 0xfc25ffff | 0x240000;
  DAT_02854c2c[8] = DAT_02854c2c[8] & 0xffffdbff | 0x1b00;
  puVar4 = DAT_02854c2c;
  if (DAT_02854c2c == (undefined4 *)0x0) {
    uVar5 = 0;
  }
  else {
    if ((DAT_0097f9b8 != DAT_02854c2c[8]) || (DAT_0097f9bc != DAT_02854c2c[9])) {
      FUN_005fa540(0,DAT_02854c2c + 8);
    }
    uVar5 = *puVar4;
  }
  FUN_006e5630(0,uVar5);
  puVar4 = DAT_02854c2c;
  if (DAT_02974d1c < 2) {
    if (DAT_02854c2c == (undefined4 *)0x0) {
      uVar5 = 0;
    }
    else {
      if ((DAT_0097f9c0 != DAT_02854c2c[8]) || (DAT_0097f9c4 != DAT_02854c2c[9])) {
        FUN_005fa540(1,DAT_02854c2c + 8);
      }
      uVar5 = *puVar4;
    }
    FUN_006e5630(1,uVar5);
    puVar4 = DAT_02854c2c;
    if (DAT_02854c2c == (undefined4 *)0x0) {
      uVar5 = 0;
    }
    else {
      if ((DAT_0097f9c8 != DAT_02854c2c[8]) || (DAT_0097f9cc != DAT_02854c2c[9])) {
        FUN_005fa540(2,DAT_02854c2c + 8);
      }
      uVar5 = *puVar4;
    }
    FUN_006e5630(2,uVar5);
    puVar4 = DAT_02854c2c;
    if (DAT_02854c2c == (undefined4 *)0x0) {
      uVar5 = 0;
    }
    else {
      if ((DAT_0097f9d0 != DAT_02854c2c[8]) || (DAT_0097f9d4 != DAT_02854c2c[9])) {
        FUN_005fa540(3,DAT_02854c2c + 8);
      }
      uVar5 = *puVar4;
    }
    FUN_006e5630(3,uVar5);
  }
  FUN_006e5340(0x1b,1);
  FUN_006e5340(0xf,0);
  FUN_006e5340(0x13,5);
  FUN_006e5340(0x14,6);
  FUN_006e5340(0xab,1);
  FUN_006e2420();
  FUN_006e5340(0x16,1);
  FUN_006e5340(0xf,0);
  FUN_006e5340(0x1b,0);
  FUN_006e5340(7,0);
  FUN_006e5340(0xa8,0xf);
  return;
}

