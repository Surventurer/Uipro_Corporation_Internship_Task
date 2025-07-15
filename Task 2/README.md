
# Deployment Report

## 🚀 Render Deployment

### 📌 Project: **invest_insight**

- **Platform:** [Render](https://render.com)
- **Framework:** Django
- **Runtime:** Python
- **Build Command:** `./build.sh`
- **Start Command:** `gunicorn investing.wsgi:application`
- **Auto-Deploy:** Enabled (on Git commit)
- **Domain:** [https://invest-insight.onrender.com/](https://invest-insight.onrender.com/)

#### 🔧 Build Script (`build.sh`)
```bash
#!/usr/bin/env bash
set -o errexit
echo "Installing dependencies..."
pip install --no-cache-dir -r requirements.txt
echo "Running collectstatic..."
python manage.py collectstatic --noinput
echo "Running migrations..."
python manage.py migrate
echo "Build completed successfully!"
```

---

### 📌 Project: **steganography_website**

- **Platform:** [Render](https://render.com)
- **Frontend:** Next.js  
- **Backend:** Flask (Python)  
- **Backend Location:** `src/backend/`  
- **Package Manager:** uv  
- **Domain:** [https://steganography-website-crxq.onrender.com/](https://steganography-website-crxq.onrender.com/)

#### 🔧 Backend Deployment Configuration
- **Build Command:**  
  `uv sync --frozen && uv cache prune --ci`
- **Start Command:**  
  `uv run main.py`
- **Entry File:**  
  `main.py` with `app = Flask(__name__)`

---

## ▲ Vercel Deployment

### 📌 Project: **steganography-website**

- **Platform:** [Vercel](https://vercel.com)
- **Framework:** Next.js (auto-detected)
- **Repository:** Connected to GitHub
- **Deployment Trigger:** On push to main branch
- **Domain:** [https://steganography-website-one.vercel.app/](https://steganography-website-one.vercel.app/)

#### ⚙️ Framework Settings
- **Build Command:** Detected automatically as `next build`
- **Output Directory:** Next.js default (`.next`)
- **Install Command:** Defaults to `yarn install`, `npm install`, or others
- **Development Command:** `next`
