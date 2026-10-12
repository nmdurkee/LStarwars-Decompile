/* Ghidra analysis pseudocode, not original source.
 * ev_87e0baa87b87192bf5be0b8e2e04b5bd4a3d9fde71e449b8cd1bb1bc961d5da7
 * Entry: 0x5ee250; label: FUN_005ee250
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ee250(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  float local_60;
  float local_5c;
  undefined4 local_58;
  float local_54;
  float local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  undefined4 local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  undefined4 local_30 [12];
  
  if (DAT_0097398c != 0) {
    local_60 = DAT_00966378 * -1.0;
    local_5c = DAT_0097313c * -1.0;
    local_58 = 0x3f800000;
    FUN_005b3200(&local_60,&local_60,&DAT_009736e8);
    local_54 = DAT_00966378 * -1.0;
    local_50 = DAT_0097313c;
    local_4c = 0x3f800000;
    FUN_005b3200(&local_54,&local_54,&DAT_009736e8);
    local_48 = DAT_00966378;
    local_44 = DAT_0097313c;
    local_40 = 0x3f800000;
    FUN_005b3200(&local_48,&local_48,&DAT_009736e8);
    local_3c = DAT_00966378;
    local_38 = DAT_0097313c * -1.0;
    local_34 = 0x3f800000;
    FUN_005b3200(&local_3c,&local_3c,&DAT_009736e8);
    iVar4 = 0;
    do {
      iVar1 = (int)local_30 + iVar4;
      FUN_005b3830(iVar1,(int)&local_60 + iVar4,0x3e4ccccd);
      FUN_005b37d0(iVar1,iVar1,&DAT_00971894);
      iVar4 = iVar4 + 0xc;
    } while (iVar4 < 0x30);
    if (DAT_0097394c == 1) {
      FUN_00603cc0(&DAT_00973760);
    }
    uVar2 = 0;
    puVar5 = local_30 + 1;
    do {
      uVar2 = uVar2 + 1;
      uVar3 = uVar2 & 0x80000003;
      if ((int)uVar3 < 0) {
        uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;
      }
      FUN_005dc050(_DAT_00971894,_DAT_00971898,_DAT_0097189c,puVar5[-1],*puVar5,puVar5[1],0xffffffff
                  );
      FUN_005dc050(puVar5[-1],*puVar5,puVar5[1],local_30[uVar3 * 3],local_30[uVar3 * 3 + 1],
                   local_30[uVar3 * 3 + 2],0xffff0000);
      puVar5 = puVar5 + 3;
    } while ((int)uVar2 < 4);
    if (DAT_0097394c == 1) {
      FUN_00603cc0(&DAT_00971b00);
    }
  }
  return;
}

