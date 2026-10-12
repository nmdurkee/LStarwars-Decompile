/* Ghidra pseudocode, not original source.
 * ev_17ab6c5fe37e6a0cb1bfccbcd3c83c7368534626b2237569a9f579541a9c35f4
 * Entry: 0x58b440; label: FUN_0058b440
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058b440(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  float10 fVar8;
  float local_3c;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_1c;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  local_3c = 0.0;
  if ((*(byte *)(param_1 + 0xef0) & 1) == 0) {
    iVar6 = 0;
    puVar7 = &DAT_009553e8;
    if (0 < DAT_00955568) {
      do {
        if (((((*(short *)(puVar7 + 5) == -1) ||
              (*(short *)(puVar7 + 5) != *(short *)(param_1 + 0x27e))) ||
             (*(float *)(param_1 + 0x6b8) <= 0.707)) &&
            ((fVar1 = *(float *)(param_1 + 0x1dc) + (float)puVar7[4] + _DAT_00804a8c,
             ABS(*(float *)(param_1 + 0x80) - (float)puVar7[1]) < fVar1 &&
             (ABS(*(float *)(param_1 + 0x88) - (float)puVar7[3]) < fVar1)))) &&
           (*(float *)(param_1 + 0x17c) < (float)puVar7[2] + (float)puVar7[4])) {
          uVar4 = FUN_005d0330(*puVar7);
          FUN_005d0130(*puVar7,local_c,local_18);
          iVar5 = FUN_005beff0(local_c,local_18,uVar4,param_1 + 0x178,param_1 + 0x184,
                               *(float *)(param_1 + 0x1dc) + _DAT_00804a8c,&local_30);
          if (iVar5 != 0) {
            if (((local_30 == 0.0) && (local_2c == 0.0)) && (local_28 == 0.0)) {
              local_30 = *(float *)(param_1 + 0x80);
              local_2c = *(float *)(param_1 + 0x84);
              local_28 = *(float *)(param_1 + 0x88);
            }
            else {
              FUN_005b30a0(&local_30,&local_30,uVar4);
            }
            local_24 = local_30 - (float)puVar7[1];
            local_1c = local_28 - (float)puVar7[3];
            if ((local_24 == 0.0) && (local_1c == 0.0)) {
              *(float *)(param_1 + 0x200) = _DAT_00804a84;
              *(undefined4 *)(param_1 + 0x208) = 0;
              *(undefined2 *)(param_1 + 0x106e) = *(undefined2 *)(puVar7 + 5);
              return;
            }
            fVar8 = (float10)FUN_005c0240(local_24 * local_24 + local_1c * local_1c);
            fVar1 = (float)fVar8;
            fVar2 = ((float)puVar7[4] + _DAT_00804a8c) - fVar1;
            if (local_3c < fVar2) {
              fVar3 = fVar2;
              if (_DAT_00804a88 < fVar2) {
                fVar3 = _DAT_00804a88;
              }
              fVar3 = (_DAT_00804a84 * fVar3) / _DAT_00804a88;
              *(float *)(param_1 + 0x200) = (fVar3 * local_24) / fVar1;
              *(float *)(param_1 + 0x208) = (fVar3 * local_1c) / fVar1;
              *(undefined2 *)(param_1 + 0x106e) = *(undefined2 *)(puVar7 + 5);
              local_3c = fVar2;
            }
          }
        }
        iVar6 = iVar6 + 1;
        puVar7 = puVar7 + 6;
        if (DAT_00955568 <= iVar6) {
          return;
        }
      } while( true );
    }
  }
  return;
}

