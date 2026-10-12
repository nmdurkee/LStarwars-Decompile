/* Ghidra pseudocode, not original source.
 * ev_742d340bc2a041ef5ff6078bdc4a89a7f4acdb81012c0f9f5c92fd03ca8daa18
 * Entry: 0x5f9c30; label: FUN_005f9c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f9c30(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  FUN_006e56c0(DAT_02854c04);
  FUN_006e5340(0xe,0);
  FUN_006e5340(0x1b,1);
  FUN_006e5340(0x13,1);
  FUN_006e5340(0x14,2);
  FUN_006e5340(7,1);
  FUN_006e5340(0x36,1);
  FUN_006e5340(0x34,1);
  FUN_006e5340(0x38,8);
  FUN_006e5340(0x37,4);
  FUN_006e5340(0x39,1);
  FUN_006e5340(0x16,3);
  iVar1 = 0;
  if (DAT_00973fec != 0) {
    puVar3 = &DAT_00963f94;
    do {
      FUN_006e49b0(6,2,puVar3,0x10);
      iVar1 = iVar1 + 4;
      puVar3 = puVar3 + 0x10;
    } while (iVar1 != DAT_00973fec);
  }
  uVar2 = 0;
  if (DAT_00973ff0 != 0) {
    do {
      FUN_006e49b0(6,(&DAT_0096e568)[uVar2] + -2,&DAT_00963f94 + (&DAT_00963f88)[uVar2] * 4,0x40);
      uVar2 = uVar2 + 1;
    } while (uVar2 < DAT_00973ff0);
  }
  FUN_006e5340(0x16,2);
  FUN_006e5340(0x37,5);
  iVar1 = 0;
  if (DAT_00973fec != 0) {
    puVar3 = &DAT_00963f94;
    do {
      FUN_006e49b0(6,2,puVar3,0x10);
      iVar1 = iVar1 + 4;
      puVar3 = puVar3 + 0x10;
    } while (iVar1 != DAT_00973fec);
  }
  uVar2 = 0;
  if (DAT_00973ff0 != 0) {
    do {
      FUN_006e49b0(6,(&DAT_0096e568)[uVar2] + -2,&DAT_00963f94 + (&DAT_00963f88)[uVar2] * 4,0x40);
      uVar2 = uVar2 + 1;
    } while (uVar2 < DAT_00973ff0);
  }
  return;
}

