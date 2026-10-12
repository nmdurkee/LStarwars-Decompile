/* Ghidra pseudocode, not original source.
 * ev_82279d4937da693375712195ef93cdd3155885c4c37192da562bbaf9be35e879
 * Entry: 0x4e77e0; label: FUN_004e77e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e77e0(void)

{
  undefined4 uVar1;
  int *piVar2;
  
  if ((DAT_00800224 == '\0') && (DAT_00855de0 != 0)) {
    DAT_00800224 = '\x01';
  }
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0088a290,"rebelcruiser2",0);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0088a29c,"transport3",0);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0088a2a8,"transport2",0);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0088a2c0,"transport1",0);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0088a2cc,"rebelcruiser1",0);
  FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0088a2d8,"transport4",0);
  uVar1 = FUN_005cf9e0(&DAT_0088a2d8);
  if ((DAT_0088a3c8 != 0) && (*(int *)(DAT_0088a3c8 + 0xe4) == 0)) {
    *(undefined4 *)(DAT_0088a3c8 + 0xe4) = uVar1;
    *(undefined1 *)(DAT_0088a3c8 + 300) = 2;
  }
  if ((DAT_0088a3cc != 0) && (*(int *)(DAT_0088a3cc + 0xe4) == 0)) {
    *(undefined4 *)(DAT_0088a3cc + 0xe4) = uVar1;
    *(undefined1 *)(DAT_0088a3cc + 300) = 2;
  }
  uVar1 = FUN_005cf9e0(&DAT_0088a290);
  if ((DAT_0088a3d0 != 0) && (*(int *)(DAT_0088a3d0 + 0xe4) == 0)) {
    *(undefined4 *)(DAT_0088a3d0 + 0xe4) = uVar1;
    *(undefined1 *)(DAT_0088a3d0 + 300) = 2;
  }
  if ((DAT_0088a3d4 != 0) && (*(int *)(DAT_0088a3d4 + 0xe4) == 0)) {
    *(undefined4 *)(DAT_0088a3d4 + 0xe4) = uVar1;
    *(undefined1 *)(DAT_0088a3d4 + 300) = 2;
  }
  if ((DAT_0088a3d8 != 0) && (*(int *)(DAT_0088a3d8 + 0xe4) == 0)) {
    *(undefined4 *)(DAT_0088a3d8 + 0xe4) = uVar1;
    *(undefined1 *)(DAT_0088a3d8 + 300) = 2;
  }
  if ((DAT_0088a3dc != 0) && (*(int *)(DAT_0088a3dc + 0xe4) == 0)) {
    *(undefined4 *)(DAT_0088a3dc + 0xe4) = uVar1;
    *(undefined1 *)(DAT_0088a3dc + 300) = 2;
  }
  uVar1 = FUN_005cf9e0(&DAT_0088a29c);
  if ((DAT_0088a3e0 != 0) && (*(int *)(DAT_0088a3e0 + 0xe4) == 0)) {
    *(undefined4 *)(DAT_0088a3e0 + 0xe4) = uVar1;
    *(undefined1 *)(DAT_0088a3e0 + 300) = 2;
  }
  if ((DAT_0088a3e4 != 0) && (*(int *)(DAT_0088a3e4 + 0xe4) == 0)) {
    *(undefined4 *)(DAT_0088a3e4 + 0xe4) = uVar1;
    *(undefined1 *)(DAT_0088a3e4 + 300) = 2;
  }
  uVar1 = FUN_005cf9e0(&DAT_0088a2cc);
  if ((DAT_0088a3f0 != 0) && (*(int *)(DAT_0088a3f0 + 0xe4) == 0)) {
    *(undefined4 *)(DAT_0088a3f0 + 0xe4) = uVar1;
    *(undefined1 *)(DAT_0088a3f0 + 300) = 2;
  }
  if ((DAT_0088a3f4 != 0) && (*(int *)(DAT_0088a3f4 + 0xe4) == 0)) {
    *(undefined4 *)(DAT_0088a3f4 + 0xe4) = uVar1;
    *(undefined1 *)(DAT_0088a3f4 + 300) = 2;
  }
  if ((DAT_0088a3f8 != 0) && (*(int *)(DAT_0088a3f8 + 0xe4) == 0)) {
    *(undefined4 *)(DAT_0088a3f8 + 0xe4) = uVar1;
    *(undefined1 *)(DAT_0088a3f8 + 300) = 2;
  }
  if ((DAT_0088a3fc != 0) && (*(int *)(DAT_0088a3fc + 0xe4) == 0)) {
    *(undefined4 *)(DAT_0088a3fc + 0xe4) = uVar1;
    *(undefined1 *)(DAT_0088a3fc + 300) = 2;
  }
  uVar1 = FUN_005cf9e0(&DAT_0088a2c0);
  if ((DAT_0088a400 != 0) && (*(int *)(DAT_0088a400 + 0xe4) == 0)) {
    *(undefined4 *)(DAT_0088a400 + 0xe4) = uVar1;
    *(undefined1 *)(DAT_0088a400 + 300) = 2;
  }
  if ((DAT_0088a404 != 0) && (*(int *)(DAT_0088a404 + 0xe4) == 0)) {
    *(undefined4 *)(DAT_0088a404 + 0xe4) = uVar1;
    *(undefined1 *)(DAT_0088a404 + 300) = 2;
  }
  if ((DAT_00800224 == '\x01') && (DAT_00855de0 == 0)) {
    piVar2 = &DAT_0088a3cc;
    do {
      if (piVar2[-1] != 0) {
        *(undefined4 *)(piVar2[-1] + 0xfc) = 0x40000000;
      }
      if (*piVar2 != 0) {
        *(undefined4 *)(*piVar2 + 0xfc) = 0x40000000;
      }
      if (piVar2[1] != 0) {
        *(undefined4 *)(piVar2[1] + 0xfc) = 0x40000000;
      }
      if (piVar2[2] != 0) {
        *(undefined4 *)(piVar2[2] + 0xfc) = 0x40000000;
      }
      if (piVar2[3] != 0) {
        *(undefined4 *)(piVar2[3] + 0xfc) = 0x40000000;
      }
      if (piVar2[4] != 0) {
        *(undefined4 *)(piVar2[4] + 0xfc) = 0x40000000;
      }
      if (piVar2[5] != 0) {
        *(undefined4 *)(piVar2[5] + 0xfc) = 0x40000000;
      }
      if (piVar2[6] != 0) {
        *(undefined4 *)(piVar2[6] + 0xfc) = 0x40000000;
      }
      piVar2 = piVar2 + 8;
    } while ((int)piVar2 < 0x88a40c);
    DAT_00800224 = '\x02';
  }
  piVar2 = &DAT_0088a3c8;
  do {
    if ((*piVar2 != 0) && ((*(byte *)(*piVar2 + 0x13a) & 0x20) != 0)) {
      DAT_0088a532 = DAT_0088a532 + -1;
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 1;
  } while ((int)piVar2 < 0x88a408);
  if (0.0 < _DAT_0088a548) {
    _DAT_0088a548 = _DAT_0088a548 - _DAT_00925018;
  }
  if ((((DAT_0088a532 == '\0') && (DAT_00951b50 == 0)) &&
      (DAT_0087a9cc = _DAT_00925018 + DAT_0087a9cc, _DAT_0088a548 < 0.0 != (_DAT_0088a548 == 0.0)))
     && (12.0 < DAT_0087a9cc != (DAT_0087a9cc == 12.0))) {
    if (DAT_0093b2a4 != 0) {
      FUN_0057a580();
      return;
    }
    FUN_0057a580();
    return;
  }
  return;
}

