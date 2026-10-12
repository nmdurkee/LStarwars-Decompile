/* Ghidra pseudocode, not original source.
 * ev_bd8f422ab2bc288e381e81a075ad63116995ee03e48e3608bccd82f55c6aad54
 * Entry: 0x5d9850; label: FUN_005d9850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d9850(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *in_EAX;
  
  puVar2 = (undefined4 *)in_EAX[0x20];
  in_EAX[3] = _DAT_00963f78;
  sVar1 = *(short *)(in_EAX + 0x27);
  in_EAX[7] = _DAT_00963f7c;
  in_EAX[0xb] = _DAT_00963f80;
  in_EAX[0xf] = _DAT_00963f84;
  in_EAX[0x10] = _DAT_00963f78;
  in_EAX[0x14] = _DAT_00963f7c;
  in_EAX[0x18] = _DAT_00963f80;
  in_EAX[0x1c] = _DAT_00963f84;
  in_EAX[0x11] = _DAT_00963f78;
  in_EAX[0x15] = _DAT_00963f7c;
  in_EAX[0x19] = _DAT_00963f80;
  in_EAX[0x1d] = _DAT_00963f84;
  in_EAX[0x12] = _DAT_00963f78;
  in_EAX[0x16] = _DAT_00963f7c;
  in_EAX[0x1a] = _DAT_00963f80;
  in_EAX[0x1e] = _DAT_00963f84;
  in_EAX[0x13] = _DAT_00963f78;
  in_EAX[0x17] = _DAT_00963f7c;
  in_EAX[0x1b] = _DAT_00963f80;
  in_EAX[0x1f] = _DAT_00963f84;
  *in_EAX = *puVar2;
  in_EAX[4] = puVar2[1];
  in_EAX[8] = puVar2[2];
  in_EAX[0xc] = puVar2[3];
  in_EAX[1] = puVar2[4];
  in_EAX[5] = puVar2[5];
  in_EAX[9] = puVar2[6];
  in_EAX[0xd] = puVar2[7];
  in_EAX[2] = puVar2[8];
  in_EAX[6] = puVar2[9];
  in_EAX[10] = puVar2[10];
  in_EAX[0xe] = puVar2[0xb];
  if (3 < sVar1) {
    in_EAX[3] = puVar2[0xc];
    in_EAX[7] = puVar2[0xd];
    in_EAX[0xb] = puVar2[0xe];
    in_EAX[0xf] = puVar2[0xf];
    if (4 < sVar1) {
      in_EAX[0x10] = puVar2[0x10];
      in_EAX[0x14] = puVar2[0x11];
      in_EAX[0x18] = puVar2[0x12];
      in_EAX[0x1c] = puVar2[0x13];
      if (5 < sVar1) {
        in_EAX[0x11] = puVar2[0x14];
        in_EAX[0x15] = puVar2[0x15];
        in_EAX[0x19] = puVar2[0x16];
        in_EAX[0x1d] = puVar2[0x17];
        if (6 < sVar1) {
          in_EAX[0x12] = puVar2[0x18];
          in_EAX[0x16] = puVar2[0x19];
          in_EAX[0x1a] = puVar2[0x1a];
          in_EAX[0x1e] = puVar2[0x1b];
          if (7 < sVar1) {
            in_EAX[0x13] = puVar2[0x1c];
            in_EAX[0x17] = puVar2[0x1d];
            in_EAX[0x1b] = puVar2[0x1e];
            in_EAX[0x1f] = puVar2[0x1f];
          }
        }
      }
    }
  }
  return;
}

