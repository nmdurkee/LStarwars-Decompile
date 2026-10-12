/* Ghidra pseudocode, not original source.
 * ev_96df89c4daae28ff35d834560256e783041bc073304993e474c02e03eab098bd
 * Entry: 0x490250; label: FUN_00490250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00490250(int param_1)

{
  ushort uVar1;
  float fVar2;
  byte bVar3;
  ushort *puVar4;
  int iVar5;
  ushort local_4;
  
  if ((*(int *)(param_1 + 0x5068) != 0) && (iVar5 = 0, 0 < *(int *)(param_1 + 0x506c))) {
    puVar4 = (ushort *)(*(int *)(param_1 + 0x5068) + 0x94);
    do {
      uVar1 = *puVar4;
      bVar3 = (byte)uVar1 >> 1;
      if (((bVar3 & 1) == 0) && ((uVar1 & 0x1800) == 0)) {
        puVar4[-3] = bVar3 & 1;
      }
      else {
        if ((bVar3 & 1) == 0) {
          *puVar4 = uVar1 | 2;
        }
        if (*(float *)(puVar4 + -0xc) <= 0.0) {
          uVar1 = *puVar4;
          bVar3 = (byte)uVar1 >> 6;
          if (((bVar3 & 1) == 0) && ((uVar1 & 0x1000) == 0)) {
            if ((*(float *)(puVar4 + -0xe) < 1.0) &&
               (fVar2 = *(float *)(puVar4 + -0xe) + _DAT_00925018, *(float *)(puVar4 + -0xe) = fVar2
               , 1.0 < fVar2)) {
              puVar4[-0xffffffff0000000e] = 0;
              puVar4[-0xffffffff0000000d] = 0x3f80;
              FUN_00681f40("SwLever",puVar4 + -0x16);
              if ((*puVar4 & 0x20) != 0) {
                *(undefined4 *)(puVar4 + -0xc) = *(undefined4 *)(puVar4 + -10);
              }
            }
          }
          else {
            if ((bVar3 & 1) == 0) {
              *puVar4 = uVar1 | 0x40;
            }
            fVar2 = *(float *)(puVar4 + -0xe) - _DAT_00925018;
            *(float *)(puVar4 + -0xe) = fVar2;
            if (fVar2 < 0.0 != (fVar2 == 0.0)) {
              *puVar4 = *puVar4 & 0xefb0;
              puVar4[-0xffffffff0000000e] = 0;
              puVar4[-0xffffffff0000000d] = 0;
              puVar4[-0xffffffff0000000c] = 0;
              puVar4[-0xffffffff0000000b] = 0;
              puVar4[-0xffffffff00000010] = 0;
              puVar4[-0xffffffff0000000f] = 0;
            }
          }
        }
        else {
          fVar2 = *(float *)(puVar4 + -0xc) - _DAT_00925018;
          *(float *)(puVar4 + -0xc) = fVar2;
          if (fVar2 < 0.0 != (fVar2 == 0.0)) {
            puVar4[-0xffffffff0000000c] = 0;
            puVar4[-0xffffffff0000000b] = 0;
            puVar4[-0xffffffff0000000e] = 0x999a;
            puVar4[-0xffffffff0000000d] = 0x3f19;
            *puVar4 = *puVar4 & 0xf7ff | 0x1040;
          }
        }
        local_4 = (ushort)(int)ROUND(*(float *)(puVar4 + -0xe) * -32768.0);
        puVar4[-3] = local_4;
      }
      iVar5 = iVar5 + 1;
      puVar4 = puVar4 + 0x50;
    } while (iVar5 < *(int *)(param_1 + 0x506c));
  }
  return;
}

