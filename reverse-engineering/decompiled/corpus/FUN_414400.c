/* Ghidra analysis pseudocode, not original source.
 * ev_c05bc3de3023c0a6cb52f4e362146021e78fd9035a9b4ae5f12ca5d880999daa
 * Entry: 0x414400; label: FUN_00414400
 */

void FUN_00414400(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_0055bd00(8,8,0,0,0xffffffff,FUN_004b3390,FUN_004a9b80,0);
  FUN_0055bd00(&DAT_01000010,0x10,0,0,0xffffffff,&LAB_004b5ef0,0,0);
  FUN_0055bd00(0x30,0x30,0,0,0xffffffff,&LAB_004b5ef0,&LAB_004aa2c0,0);
  FUN_0055bd00(0x50,0x50,0,0,0xffffffff,&LAB_004b5ef0,&LAB_004a9e40,&LAB_004a9f60);
  FUN_0055bd00(0,0,0x800,0x800,0xffffffff,FUN_004b30e0,&LAB_004a9900,0);
  FUN_0055bd00(0x2000,0x2000,0,0,0xffffffff,0x4b5120,&LAB_004a9730,0);
  FUN_0055bd00(0x40000000,0x40000000,0,0,0xffffffff,FUN_004b3000,&LAB_004a9800,0);
  FUN_0055bd00(0,0,0,0,4,&LAB_004b5ef0,&LAB_004aa490,0);
  FUN_0055bd00(0,0,0,0,0x11,FUN_004b38e0,&LAB_004aab20,0);
  FUN_0055bd00(0,0,0,0,0xf,FUN_004b62f0,&LAB_004aaac0,0);
  FUN_0055bd00(0,0,0,0,0x10,FUN_004b6430,&LAB_004aac50,0);
  FUN_0055bd00(0,0,0,0,0x12,FUN_004b39f0,&LAB_004aab80,0);
  FUN_0055bd00(0,0,0,0,0x12,FUN_004b39f0,&LAB_004aab80,0);
  FUN_0055bd00(0,0,0,0,0x14,FUN_004b6800,FUN_004ab910,0);
  FUN_0055bd00(0,0,0,0,2,0,0,FUN_004a9320);
  FUN_0055bd00(0,0,0,0,0,FUN_004b5820,&LAB_004a9940,0);
  iVar1 = 0;
  if (0 < DAT_0093b278) {
    iVar2 = 0;
    iVar3 = 0;
    do {
      if ((*(uint *)(iVar3 + 0x94 + DAT_0093b284) & 0x10000000) != 0) {
        *(undefined1 **)(iVar2 + 0x18 + DAT_0093b274) = &LAB_004b65f0;
        *(undefined1 **)(iVar2 + 0x1c + DAT_0093b274) = &LAB_004ab100;
      }
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x120;
      iVar2 = iVar2 + 0x4c;
    } while (iVar1 < DAT_0093b278);
  }
  if (DAT_007f1900 != -1) {
    *(code **)(DAT_007f1900 * 0x4c + 0x18 + DAT_0093b274) = FUN_004b6520;
    *(undefined1 **)(DAT_007f1900 * 0x4c + 0x1c + DAT_0093b274) = &LAB_004ab010;
  }
  if (DAT_007f1acc != -1) {
    *(code **)(DAT_007f1acc * 0x4c + 0x18 + DAT_0093b274) = FUN_004b6520;
    *(undefined1 **)(DAT_007f1acc * 0x4c + 0x1c + DAT_0093b274) = &LAB_004ab010;
  }
  if (DAT_007f1904 != -1) {
    *(code **)(DAT_007f1904 * 0x4c + 0x18 + DAT_0093b274) = FUN_004b5e10;
    *(undefined1 **)(DAT_007f1904 * 0x4c + 0x1c + DAT_0093b274) = &LAB_004aa670;
  }
  if (DAT_007f18fc != -1) {
    *(code **)(DAT_007f18fc * 0x4c + 0x18 + DAT_0093b274) = FUN_004b3b50;
    *(undefined1 **)(DAT_007f18fc * 0x4c + 0x1c + DAT_0093b274) = &LAB_004aac10;
  }
  if (DAT_007f197c != -1) {
    *(code **)(DAT_007f197c * 0x4c + 0x18 + DAT_0093b274) = FUN_004b3b80;
  }
  if (DAT_007f1a30 != -1) {
    *(code **)(DAT_007f1a30 * 0x4c + 0x18 + DAT_0093b274) = FUN_004b3b80;
  }
  if (DAT_007f191c != -1) {
    *(code **)(DAT_007f191c * 0x4c + 0x18 + DAT_0093b274) = FUN_004b3240;
  }
  if (DAT_007f19f8 != -1) {
    *(undefined **)(DAT_007f19f8 * 0x4c + 0x18 + DAT_0093b274) = &DAT_004b5d30;
    *(undefined1 **)(DAT_007f19f8 * 0x4c + 0x1c + DAT_0093b274) = &LAB_004aa630;
  }
  if (DAT_007f19fc != -1) {
    *(undefined **)(DAT_007f19fc * 0x4c + 0x18 + DAT_0093b274) = &DAT_004b5d30;
    *(undefined1 **)(DAT_007f19fc * 0x4c + 0x1c + DAT_0093b274) = &LAB_004aa630;
  }
  if (DAT_007f1948 != -1) {
    *(code **)(DAT_007f1948 * 0x4c + 0x18 + DAT_0093b274) = FUN_004b2cb0;
    *(undefined1 **)(DAT_007f1948 * 0x4c + 0x1c + DAT_0093b274) = &LAB_004a97c0;
  }
  if (DAT_007f18b4 != -1) {
    *(undefined1 **)(DAT_007f18b4 * 0x4c + 0x1c + DAT_0093b274) = &LAB_004a9b70;
  }
  if (DAT_007f187c != -1) {
    *(code **)(DAT_007f187c * 0x4c + 0x18 + DAT_0093b274) = FUN_004b3390;
    *(code **)(DAT_007f187c * 0x4c + 0x1c + DAT_0093b274) = FUN_004a9b80;
  }
  if (DAT_007f1878 != -1) {
    *(code **)(DAT_007f1878 * 0x4c + 0x18 + DAT_0093b274) = FUN_004b3390;
    *(code **)(DAT_007f1878 * 0x4c + 0x1c + DAT_0093b274) = FUN_004a9b80;
  }
  return;
}

