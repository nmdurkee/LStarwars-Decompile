/* Ghidra pseudocode, not original source.
 * ev_77c3e64cbf166009276f17c020938a120e86ba2ebeb248b147f617680a486917
 * Entry: 0x607880; label: FUN_00607880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00607880(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar4 = param_1;
  iVar3 = DAT_02854c20;
  if (((param_1 != (undefined4 *)0x0) && (iVar5 = FUN_00741610(), iVar5 != 0)) && (puVar4[6] != 0))
  {
    uVar2 = puVar4[1];
    if ((*(uint *)(iVar3 + 0x26c) & 0x4000000) != 0) {
      FUN_005fde60();
    }
    puVar1 = puVar4 + 0xe;
    switch(*puVar4) {
    case 6:
      if ((puVar4[10] != 0) && (puVar4[0xd] != 0)) {
        FUN_006e5b90(0,0,&param_1,0x2000,puVar4[0xc]);
        FUN_004ef660(param_1,puVar4[0xd],(uint)*(ushort *)(puVar4 + 2) * puVar4[6]);
        FUN_006e5bc0(puVar4[0xc]);
        FUN_006e5590(0,puVar4[0xc],0,*(undefined2 *)(puVar4 + 2));
        FUN_006e51d0(puVar4[8]);
        FUN_006e48e0(5,0,0,puVar4[6],puVar4[7],uVar2);
        return;
      }
      FUN_006e5590(0,puVar4[9],0,*(undefined2 *)(puVar4 + 2));
      FUN_006e51d0(puVar4[8]);
      FUN_006e48e0(5,puVar4[5],0,puVar4[6],puVar4[7],uVar2);
      return;
    case 0xc:
      FUN_006e49b0(4,(uint)puVar4[6] / 3,puVar1,0x18);
      return;
    case 0xd:
      if (2 < (uint)puVar4[6]) {
        FUN_006e49b0(5,puVar4[6] - 2,puVar1,0x18);
        return;
      }
      break;
    case 0xe:
      FUN_006e49b0(2,(uint)puVar4[6] >> 1,puVar1,0x18);
      return;
    case 0xf:
      FUN_006e49b0(3,puVar4[6] + -1,puVar1,0x18);
      return;
    case 0x11:
      if (2 < (uint)puVar4[6]) {
        FUN_006e49b0(6,puVar4[6] - 2,puVar1,0x18);
        return;
      }
      break;
    case 0x12:
      param_1 = (undefined4 *)0x42000000;
      FUN_006e5340(0x9a,0x42000000);
      FUN_006e49b0(1,puVar4[6],puVar1,0x18);
      param_1 = (undefined4 *)0x3f800000;
      FUN_006e5340(0x9a,0x3f800000);
    }
  }
  return;
}

