/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5c8a00; label: FUN_005c8a00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c8a00(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = param_1;
  puVar3 = in_ECX;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = param_1 + 0x10;
  puVar3 = in_ECX + 0x10;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = param_1 + 0x20;
  puVar3 = in_ECX + 0x20;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = param_1 + 0x30;
  puVar3 = in_ECX + 0x30;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  in_ECX[0x40] = param_1[0x40];
  in_ECX[0x41] = param_1[0x41];
  in_ECX[0x42] = param_1[0x42];
  in_ECX[0x43] = param_1[0x43];
  in_ECX[0x44] = param_1[0x44];
  in_ECX[0x48] = param_1[0x48];
  in_ECX[0x49] = param_1[0x49];
  in_ECX[0x4a] = param_1[0x4a];
  in_ECX[0x4b] = param_1[0x4b];
  in_ECX[0x4c] = param_1[0x4c];
  in_ECX[0x4d] = param_1[0x4d];
  in_ECX[0x4e] = param_1[0x4e];
  in_ECX[0x4f] = param_1[0x4f];
  in_ECX[0x50] = param_1[0x50];
  in_ECX[0x51] = param_1[0x51];
  in_ECX[0x52] = param_1[0x52];
  in_ECX[0x53] = param_1[0x53];
  in_ECX[0x54] = param_1[0x54];
  in_ECX[0x55] = param_1[0x55];
  in_ECX[0x56] = param_1[0x56];
  in_ECX[0x57] = param_1[0x57];
  in_ECX[0x58] = param_1[0x58];
  in_ECX[0x59] = param_1[0x59];
  in_ECX[0x5a] = param_1[0x5a];
  in_ECX[0x5b] = param_1[0x5b];
  in_ECX[0x5c] = param_1[0x5c];
  in_ECX[0x5d] = param_1[0x5d];
  in_ECX[0x5e] = param_1[0x5e];
  in_ECX[0x5f] = param_1[0x5f];
  in_ECX[0x60] = param_1[0x60];
  in_ECX[0x61] = param_1[0x61];
  in_ECX[0x62] = param_1[0x62];
  iVar1 = 2;
  in_ECX[99] = param_1[99];
  in_ECX[100] = param_1[100];
  in_ECX[0x65] = param_1[0x65];
  in_ECX[0x66] = param_1[0x66];
  in_ECX[0x67] = param_1[0x67];
  puVar2 = in_ECX + 0x69;
  puVar3 = param_1 + 0x6b;
  do {
    puVar2[-1] = puVar3[-3];
    iVar1 = iVar1 + -1;
    *puVar2 = *(undefined4 *)((int)param_1 + (-0x60 - (int)in_ECX) + (int)(puVar2 + 0x18));
    puVar2[1] = puVar3[-1];
    puVar2[2] = *puVar3;
    puVar2[3] = puVar3[1];
    puVar2[4] = puVar3[2];
    puVar2[5] = puVar3[3];
    puVar2[6] = puVar3[4];
    puVar2[7] = puVar3[5];
    puVar2[8] = puVar3[6];
    puVar2[9] = puVar3[7];
    puVar2[10] = puVar3[8];
    puVar2[0xb] = puVar3[9];
    puVar2[0xc] = puVar3[10];
    puVar2[0xd] = puVar3[0xb];
    puVar2[0xe] = puVar3[0xc];
    puVar2[0xf] = puVar3[0xd];
    puVar2[0x10] = puVar3[0xe];
    puVar2[0x11] = puVar3[0xf];
    puVar2[0x12] = puVar3[0x10];
    puVar2[0x13] = puVar3[0x11];
    puVar2[0x14] = puVar3[0x12];
    puVar2[0x15] = puVar3[0x13];
    puVar2[0x16] = puVar3[0x14];
    puVar2 = puVar2 + 0x18;
    puVar3 = puVar3 + 0x18;
  } while (iVar1 != 0);
  in_ECX[0x98] = param_1[0x98];
  in_ECX[0x9c] = param_1[0x9c];
  in_ECX[0x9d] = param_1[0x9d];
  in_ECX[0x9e] = param_1[0x9e];
  in_ECX[0x9f] = param_1[0x9f];
  in_ECX[0xa0] = param_1[0xa0];
  in_ECX[0xa1] = param_1[0xa1];
  in_ECX[0xa2] = param_1[0xa2];
  in_ECX[0xa3] = param_1[0xa3];
  in_ECX[0xa4] = param_1[0xa4];
  in_ECX[0xa5] = param_1[0xa5];
  in_ECX[0xa6] = param_1[0xa6];
  in_ECX[0xa7] = param_1[0xa7];
  in_ECX[0xa8] = param_1[0xa8];
  puVar2 = param_1 + 0xa9;
  puVar3 = in_ECX + 0xa9;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = param_1 + 0xba;
  puVar3 = in_ECX + 0xba;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  in_ECX[0xcb] = param_1[0xcb];
  in_ECX[0xcc] = param_1[0xcc];
  in_ECX[0xcd] = param_1[0xcd];
  in_ECX[0xce] = param_1[0xce];
  in_ECX[0xcf] = param_1[0xcf];
  in_ECX[0xd0] = param_1[0xd0];
  in_ECX[0xd1] = param_1[0xd1];
  in_ECX[0xd2] = param_1[0xd2];
  in_ECX[0xd3] = param_1[0xd3];
  in_ECX[0xd4] = param_1[0xd4];
  in_ECX[0xd5] = param_1[0xd5];
  in_ECX[0xd6] = param_1[0xd6];
  in_ECX[0xd7] = param_1[0xd7];
  in_ECX[0xd8] = param_1[0xd8];
  in_ECX[0xd9] = param_1[0xd9];
  in_ECX[0xda] = param_1[0xda];
  in_ECX[0xdb] = param_1[0xdb];
  in_ECX[0xdc] = param_1[0xdc];
  in_ECX[0xdd] = param_1[0xdd];
  return;
}

