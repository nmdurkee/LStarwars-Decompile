/* Ghidra analysis pseudocode, not original source.
 * ev_14516b90afd78e4126f0b3f4a370dbc2a5912f8e0102dea09dbec3c8384d0f78
 * Entry: 0x6e42d0; label: FUN_006e42d0
 */

void FUN_006e42d0(void)

{
  uint uVar1;
  uint *_Base;
  undefined4 uVar2;
  undefined4 *in_ECX;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = 0;
  uVar1 = (**(code **)(*DAT_029765c8 + 0x18))(DAT_029765c8,0,0x16);
  _Base = (uint *)FUN_006ea018(-(uint)((int)((ulonglong)uVar1 * 0x10 >> 0x20) != 0) |
                               (uint)((ulonglong)uVar1 * 0x10));
  uVar5 = 0x280;
  uVar6 = 0x1e0;
  if ((DAT_008264b0 == 2) || (DAT_008264bc == 2)) {
    uVar5 = 800;
    uVar6 = 600;
  }
  in_ECX[0x186] = 0;
  puVar4 = _Base;
  if (uVar1 != 0) {
    do {
      (**(code **)(*(int *)*in_ECX + 0x1c))((int *)*in_ECX,0,0x16,uVar3,puVar4);
      if ((((*puVar4 < uVar5) || (puVar4[1] < uVar6)) || (puVar4[2] < 0x28)) || (0x55 < puVar4[2]))
      {
        *puVar4 = 0;
        puVar4[1] = 0;
        puVar4[2] = 0;
        puVar4[3] = 0;
      }
      else {
        in_ECX[0x186] = in_ECX[0x186] + 1;
      }
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 4;
    } while (uVar3 != uVar1);
  }
  _qsort(_Base,uVar1,0x10,FUN_006e1b10);
  uVar2 = FUN_006ea018(-(uint)((int)((ulonglong)(uint)in_ECX[0x186] * 0x10 >> 0x20) != 0) |
                       (uint)((ulonglong)(uint)in_ECX[0x186] * 0x10));
  in_ECX[0x187] = uVar2;
  FUN_004ef660(uVar2,_Base,in_ECX[0x186] << 4);
  _free(_Base);
  if ((DAT_008264c7 != '\0') && (DAT_00826490 != 6)) {
    FUN_006daf60(0);
  }
  uVar1 = FUN_006e1b70(DAT_00826474,DAT_00826478,DAT_0082648c);
  if (uVar1 < (uint)in_ECX[0x186]) {
    in_ECX[0x198] = uVar1;
  }
  else {
    in_ECX[0x198] = in_ECX[0x188];
  }
  in_ECX[0x19a] = DAT_00826490;
  FUN_006e3940(1);
  FUN_006e5340(7,1);
  FUN_006e5340(0x89,0);
  FUN_006e4850(&DAT_008281e0,in_ECX + 0x1a3);
  FUN_006e4850(&DAT_008281f8,in_ECX + 0x1a1);
  FUN_006e4850(&DAT_00828210,in_ECX + 0x1ab);
  return;
}

