/* Ghidra pseudocode, not original source.
 * ev_0e37ff2b068f2f451a629821c3494056628992f54992bdfe8536c4096373c130
 * Entry: 0x4e9b10; label: FUN_004e9b10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e9b10(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  int local_1c;
  float local_18;
  char local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_1c;
  local_1c = 0;
  if (DAT_0088a300 != DAT_0088a301) {
    if (DAT_0088a304 == -1) {
      if ((_DAT_0088a308 < 5.0) && (DAT_0088a301 != 1)) {
        _DAT_0088a308 = _DAT_0088a308 + _DAT_00925018;
        __security_check_cookie(local_4 ^ (uint)&local_1c);
        return;
      }
      if (DAT_0088a301 == 5) {
        _memset(&DAT_0088a30c,0,0xbc);
        if (DAT_0093b2a4 == 0) {
          FUN_0057a580((int)*(short *)(DAT_0087b1f0 + 0x62));
        }
        else {
          FUN_0057a5b0(PTR_DAT_00802c54);
        }
      }
      _DAT_0088a308 = 0.0;
      _sprintf(local_14,"CamCut_%d",(uint)DAT_0088a301);
      iVar1 = FUN_0052c790(PTR_DAT_00802c54 + 0x2b00,local_14);
      if (iVar1 != 0) {
        FUN_0052cc90(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),0,0,PTR_DAT_00802c54 + 0x2b00,
                     _DAT_00925018);
      }
      DAT_0088a304 = '\0';
      _DAT_0088a308 = 0.0;
      DAT_0088a302 = 1;
LAB_004e9d28:
      local_1c = 1;
    }
    else if (DAT_0088a304 == '\0') {
      if (DAT_00855de0 != 0) {
        DAT_0088a304 = '\x01';
      }
    }
    else if (('\0' < DAT_0088a304) && (DAT_00855de0 == 0)) {
      if (DAT_0088a304 == '\x01') {
        iVar2 = 0;
        iVar1 = DAT_0093d504;
        if (0 < DAT_0093d500) {
          do {
            if (((((*(uint *)(iVar1 + 0x1fc) & 1) != 0) &&
                 ((*(uint *)(iVar1 + 0x1fc) & 0x1000) != 0)) &&
                (*(short *)(iVar1 + 0x1064) != DAT_007f1914)) &&
               ((*(char *)(iVar1 + 0x280) == -1 &&
                ((*(byte *)(*(int *)(iVar1 + 0x54) + 4) & 4) != 0)))) {
              FUN_004364e0(iVar1,4,0);
            }
            iVar2 = iVar2 + 1;
            iVar1 = iVar1 + 0x10d8;
          } while (iVar2 < DAT_0093d500);
        }
        DAT_0088a3ac = 0;
        DAT_0088a3b0 = 0;
        DAT_0088a3b4 = 0;
        DAT_0088a3b8 = 0;
        DAT_0088a3bc = 0;
        DAT_0088a3c0 = 0;
        DAT_0088a304 = '\x02';
      }
      iVar1 = FUN_004e9980();
      if (iVar1 == 0) goto LAB_004e9ecf;
      DAT_0088a304 = -1;
      DAT_0088a300 = DAT_0088a301;
      goto LAB_004e9d28;
    }
  }
  iVar1 = 0;
  if (DAT_0088a3c4 != 0) {
    do {
      FUN_004e94c0(iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)(uint)DAT_0088a3c4);
  }
  FUN_004e90e0();
  if (((DAT_0088a300 == 3) && (DAT_0088a310 != 0)) && (DAT_0088a314 != 0)) {
    local_18 = *(float *)((&DAT_0088a310)[iVar1] + 0x1dc) * 3.0;
    iVar2 = FUN_005185e0(DAT_0088a310 + 0x5c,local_18);
    uVar3 = ~(1 << (*(byte *)(DAT_0088a314 + 0x28d) & 0x1f));
    *(uint *)(iVar2 + 0x50) = uVar3;
    *(int *)(iVar2 + 0x54) = (int)uVar3 >> 0x1f;
    local_18 = *(float *)((&DAT_0088a310)[iVar1] + 0x1dc) * 3.0;
    iVar1 = FUN_005185e0(DAT_0088a314 + 0x5c,local_18);
    uVar3 = ~(1 << (*(byte *)(DAT_0088a310 + 0x28d) & 0x1f));
    *(uint *)(iVar1 + 0x50) = uVar3;
    *(int *)(iVar1 + 0x54) = (int)uVar3 >> 0x1f;
  }
  pbVar4 = &DAT_0088a322;
  do {
    pbVar5 = pbVar4 + -0x12;
    iVar1 = 4;
    uVar3 = 0;
    do {
      iVar2 = *(int *)pbVar5;
      if (iVar2 != 0) {
        if (((*(uint *)(iVar2 + 0x1fc) & 0x1000) == 0) || (*(char *)(iVar2 + 0x28b) != '\0')) {
          *pbVar4 = *pbVar4 - 1;
          pbVar4[-2] = pbVar4[-2] - 1;
          pbVar5[0] = 0;
          pbVar5[1] = 0;
          pbVar5[2] = 0;
          pbVar5[3] = 0;
          FUN_006514b0("TrueJedi_100pc",0,0x3fc00000);
        }
        else {
          uVar3 = uVar3 + 1;
        }
      }
      pbVar5 = pbVar5 + 4;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    if (*pbVar4 != uVar3) {
      *pbVar4 = (byte)uVar3;
    }
    if (pbVar4[-2] != 0) {
      local_1c = 1;
    }
    pbVar4 = pbVar4 + 0x28;
  } while ((int)pbVar4 < 0x88a3c2);
  if (((DAT_00855de0 == 0) && (local_1c == 0)) &&
     ((DAT_0087b504 == 0 && (DAT_0088a301 == DAT_0088a300)))) {
    DAT_0088a301 = DAT_0088a301 + 1;
  }
LAB_004e9ecf:
  __security_check_cookie(local_4 ^ (uint)&local_1c);
  return;
}

