function f = mechFeatures(x, fs, fr) %#codegen
% Features of one vibration window. fr = shaft frequency in Hz (from a speed sensor).
x = x(:);
N = numel(x);
w = 0.5 - 0.5*cos(2*pi*(0:N-1)'/(N-1));      % Hann window
X = abs(fft(x .* w)) * 2 / sum(w);
half = floor(N/2);
A = zeros(1,3);
for k = 1:3
    b = round(k*fr*N/fs) + 1;                % FFT bin of k-th harmonic
    b = min(max(b,3), half-2);
    m = 0;
    for d = -2:2
        m = max(m, X(b+d));
    end
    A(k) = m;
end
r = rms(x);
f = [std(x), r, max(abs(x)), kurtosis(x), max(abs(x))/r, ...
    A(1), A(2), A(3), A(2)/(A(1)+1e-6), A(3)/(A(1)+1e-6)];
end