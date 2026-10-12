/* Ghidra analysis pseudocode, not original source.
 * ev_f77d0ac966a5398976b96c42189a5c308704a96dca5e44da054727b198f01d57
 * Entry: 0x42fcf0; label: FUN_0042fcf0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042fcf0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;
  float local_78;
  float local_64;
  float local_60;
  float local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined1 local_40 [48];
  float local_10;
  float local_c;
  float local_8;
  
  if ((*(int *)(PTR_DAT_00802c54 + 0x46f4) != 0) && (*(char *)(param_1 + 0x28b) == '\0')) {
    if (*(char *)(param_1 + 0x1078) == '\x01') {
      if ((*(char *)(param_1 + 0x6c0) == '\r') || (*(char *)(param_1 + 0x6c0) == '\f')) {
        local_78 = (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) /
                   *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c)) * _DAT_007f657c;
        if (local_78 < 0.5) {
          local_78 = 0.5;
        }
        iVar7 = FUN_0062c350(local_78,_DAT_00925018);
        if (0 < iVar7) {
          local_58 = *(undefined4 *)(param_1 + 0x6a8);
          local_54 = *(undefined4 *)(param_1 + 0x6ac);
          local_50 = *(undefined4 *)(param_1 + 0x6b0);
          local_64 = *(float *)(param_1 + 0x6b4);
          local_60 = *(float *)(param_1 + 0x6b8);
          local_5c = *(float *)(param_1 + 0x6bc);
          FUN_0042fbb0(local_40,&local_64,&local_58,0,0);
          fVar3 = _DAT_00925018 * local_64;
          fVar4 = _DAT_00925018 * local_60;
          fVar5 = _DAT_00925018 * local_5c;
          if (0 < iVar7) {
            do {
              uVar6 = FUN_0054fa60();
              local_4c = fVar4;
              local_48 = -fVar5;
              local_44 = -fVar3;
              FUN_00552520(&local_4c,uVar6,&local_64);
              iVar8 = *(int *)(PTR_DAT_00802c54 + 0x46f4) +
                      *(int *)(PTR_DAT_00802c54 + 0x4700) * 0x28;
              iVar2 = *(int *)(PTR_DAT_00802c54 + 0x46f4) +
                      *(int *)(PTR_DAT_00802c54 + 0x4700) * 0x28;
              FUN_005a24f0(DAT_00876688,local_40,*(undefined4 *)(iVar2 + 0xc),
                           *(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 8),0,
                           *(undefined4 *)
                            (*(int *)(PTR_DAT_00802c54 + 0x46f4) +
                            *(int *)(PTR_DAT_00802c54 + 0x4700) * 0x28),*(undefined4 *)(iVar8 + 4),
                           0xf,*(undefined4 *)(iVar8 + 0x24),&local_4c);
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
        }
        if (*(float *)(param_1 + 0xdc0) <= 0.0) {
          FUN_00681f40("SabFField",&local_58);
          *(undefined4 *)(param_1 + 0xdc0) = _DAT_007f6578;
        }
      }
      if (0.0 < *(float *)(param_1 + 0xdc0)) {
        *(float *)(param_1 + 0xdc0) = *(float *)(param_1 + 0xdc0) - _DAT_00925018;
        return;
      }
    }
    else if ((*(char *)(param_1 + 0x287) != '\0') && (*(char *)(param_1 + 0x288) != '\0')) {
      local_78 = (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) /
                 *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c)) * 20.0;
      if (local_78 < 1.0) {
        local_78 = 1.0;
      }
      iVar7 = FUN_0062c350(local_78,_DAT_00925018);
      if (0 < iVar7) {
        local_58 = 0;
        local_54 = 0;
        local_50 = 0;
        FUN_0042fbb0(local_40,&DAT_00802500,&local_58,0,0);
        fVar3 = *(float *)(param_1 + 0x1dc);
        if (0 < iVar7) {
          do {
            iVar8 = FUN_0054fa60();
            local_10 = ((float)iVar8 * 1.5259022e-05 - 0.5) * _DAT_007f6574 +
                       *(float *)(param_1 + 0x80);
            local_c = *(float *)(param_1 + 0x220) + 0.001;
            iVar8 = FUN_0054fa60();
            local_8 = ((float)iVar8 * 1.5259022e-05 - 0.5) * _DAT_007f6574 +
                      *(float *)(param_1 + 0x88);
            iVar8 = *(int *)(PTR_DAT_00802c54 + 0x46f4) + *(int *)(PTR_DAT_00802c54 + 0x46fc) * 0x28
            ;
            _DAT_007f6570 =
                 *(float *)(param_1 + 0x1dc) + *(float *)(param_1 + 0x1dc) +
                 *(float *)(param_1 + 0x1dc);
            puVar1 = (undefined4 *)
                     (*(int *)(PTR_DAT_00802c54 + 0x46f4) +
                     *(int *)(PTR_DAT_00802c54 + 0x46fc) * 0x28);
            FUN_005a24f0(DAT_00876688,local_40,fVar3 * 0.5,_DAT_007f6570,puVar1[2],0,*puVar1,
                         *(undefined4 *)(iVar8 + 4),7,*(undefined4 *)(iVar8 + 0x24),0);
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
        }
      }
    }
  }
  return;
}

